#pragma once
#include <base/container/iterator/IEnumerable.h>
#include <memory>
#include <pcap/pcap.h>

namespace net
{
    class PcapInterfaceCollection :
        public base::IEnumerable<pcap_if_t *>
    {
    private:
        PcapInterfaceCollection(pcap_if_t *interfece_link_list);

        std::shared_ptr<pcap_if_t> _interface_link_list_head_node = nullptr;

    public:
        /// @brief 查找设备。
        /// @return 返回设备列表。
        static std::shared_ptr<PcapInterfaceCollection const> FindInterfaces();

        /// @brief 获取迭代器
        /// @return
        std::shared_ptr<base::IEnumerator<pcap_if_t *>> GetEnumerator() override;
    };
} // namespace net
