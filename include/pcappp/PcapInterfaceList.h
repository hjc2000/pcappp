#pragma once
#include <memory>
#include <pcap/pcap.h>
#include <vector>

namespace net
{
    class PcapInterfaceList
    {
    private:
        PcapInterfaceList(pcap_if_t *interfece_link_list);

        pcap_if_t *_interface_link_list_head_node = nullptr;
        std::vector<pcap_if_t *> _interfeces;

        void CopyInterfecesToVector();

    public:
        ~PcapInterfaceList();

        /// @brief 查找设备。
        /// @return 返回设备列表。
        static std::shared_ptr<PcapInterfaceList const> FindInterfaces();
    };
} // namespace net
