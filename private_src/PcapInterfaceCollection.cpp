#include "PcapInterfaceCollection.h"
#include <PcapInitializer.h>

pcappp::PcapInterfaceCollection::PcapInterfaceCollection(pcap_if_t *interfece_link_list_head_node)
{
	_interface_link_list_head_node = std::shared_ptr<pcap_if_t>{
		interfece_link_list_head_node,
		[](pcap_if_t *p)
		{
			pcap_freealldevs(p);
		},
	};
}

std::shared_ptr<pcappp::PcapInterfaceCollection const> pcappp::PcapInterfaceCollection::FindInterfaces()
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
		pcap_if_t *_current_node = nullptr;

	public:
		Enumerator(pcap_if_t *head_node)
		{
			_current_node = head_node;
		}

		///
		/// @brief 迭代器当前是否指向尾后元素。
		///
		/// @return
		///
		virtual bool IsEnd() const override
		{
			return _current_node == nullptr;
		}

		///
		/// @brief 获取当前值的引用。
		///
		/// @return ItemType&
		///
		virtual pcap_if_t *&CurrentValue() override
		{
			return _current_node;
		}

		///
		/// @brief 递增迭代器的位置。
		///
		///
		virtual void Add() override
		{
			_current_node = _current_node->next;
		}
	};
} // namespace

std::shared_ptr<base::IEnumerator<pcap_if_t *>> pcappp::PcapInterfaceCollection::GetEnumerator()
{
	return std::shared_ptr<base::IEnumerator<pcap_if_t *>>{new Enumerator{_interface_link_list_head_node.get()}};
}
