#include "Pcap.h"
#include <base/container/List.h>
#include <PcapInitializer.h>
#include <PcapInterface.h>

std::string pcappp::Pcap::Version()
{
    pcappp::PcapInitializer::Initialize();
    return std::string{pcap_lib_version()};
}

std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> pcappp::Pcap::FindInterfaces()
{
    pcappp::PcapInitializer::Initialize();
    std::shared_ptr<base::List<std::shared_ptr<pcappp::IPcapInterface>>> interface_list{new base::List<std::shared_ptr<pcappp::IPcapInterface>>{}};

    // 获取网络接口裸指针集合
    std::shared_ptr<pcappp::PcapInterfaceCollection const> raw_interfaces = pcappp::PcapInterfaceCollection::FindInterfaces();
    for (pcap_if_t *const &raw_interface : *raw_interfaces)
    {
        std::shared_ptr<pcappp::PcapInterface> interface_{new pcappp::PcapInterface{raw_interface}};
        interface_list->Add(interface_);
    }

    return interface_list;
}
