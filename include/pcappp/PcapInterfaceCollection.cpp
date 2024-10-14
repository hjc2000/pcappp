#include "PcapInterfaceCollection.h"
#include <iostream>
#include <pcappp/PcapInitializer.h>

net::PcapInterfaceCollection::PcapInterfaceCollection(pcap_if_t *interfece_link_list_head_node)
{
    net::PcapInitializer::Initialize();

    _interface_link_list_head_node = std::shared_ptr<pcap_if_t>{
        interfece_link_list_head_node,
        [](pcap_if_t *p)
        {
            pcap_freealldevs(p);
        },
    };
}

std::shared_ptr<net::PcapInterfaceCollection const> net::PcapInterfaceCollection::FindInterfaces()
{
    char error_message_buffer[1024]{};

    pcap_if_t *interfece_link_list_head_node;
    int result = pcap_findalldevs_ex(PCAP_SRC_IF_STRING,
                                     nullptr,
                                     &interfece_link_list_head_node,
                                     error_message_buffer);

    if (result)
    {
        throw std::runtime_error{std::string{error_message_buffer}};
    }

    std::shared_ptr<PcapInterfaceCollection> list{new PcapInterfaceCollection{interfece_link_list_head_node}};
    return list;
}

namespace
{
    class Enumerator :
        public base::IEnumerator<pcap_if_t *>
    {
    private:
        pcap_if_t *_head_node = nullptr;
        pcap_if_t *_current_node = nullptr;
        bool _is_first_move = true;

    public:
        Enumerator(pcap_if_t *head_node)
        {
            _head_node = head_node;
            Reset();
        }

        /// @brief 获取当前值的引用
        /// @return
        pcap_if_t *&CurrentValue() override
        {
            return _current_node;
        }

        /// @brief 迭代器前进到下一个值
        /// @return
        bool MoveNext() override
        {
            if (_is_first_move)
            {
                _is_first_move = false;
            }
            else
            {
                _current_node = _current_node->next;
            }

            return _current_node != nullptr;
        }

        /// @brief 将迭代器重置到容器开始的位置。
        /// @note 开始位置是第一个元素前。也就是说重置后，要调用一次 MoveNext 才能获取到第一个值。
        void Reset() override
        {
            _current_node = _head_node;
            _is_first_move = true;
        }
    };
} // namespace

std::shared_ptr<base::IEnumerator<pcap_if_t *>> net::PcapInterfaceCollection::GetEnumerator()
{
    return std::shared_ptr<base::IEnumerator<pcap_if_t *>>{new Enumerator{_interface_link_list_head_node.get()}};
}
