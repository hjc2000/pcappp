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

    std::shared_ptr<base::List<std::shared_ptr<pcappp::IPcapInterface>>> interface_list{
        new base::List<std::shared_ptr<pcappp::IPcapInterface>>{},
    };

    auto raw_interfaces = pcappp::PcapInterfaceCollection::FindInterfaces();
    for (auto &raw_interface : *raw_interfaces)
    {
        std::shared_ptr<pcappp::PcapInterface> interface_{
            new pcappp::PcapInterface{raw_interface, raw_interfaces},
        };

        interface_list->Add(interface_);
    }

    return interface_list;
}
