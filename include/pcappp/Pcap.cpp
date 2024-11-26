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

    // 获取网络接口裸指针集合
    std::shared_ptr<pcappp::PcapInterfaceCollection const> raw_interfaces = pcappp::PcapInterfaceCollection::FindInterfaces();
    for (pcap_if_t *const &raw_interface : *raw_interfaces)
    {
        std::shared_ptr<pcappp::PcapInterface> interface_{new pcappp::PcapInterface{raw_interface}};
        interface_list->Add(interface_);
    }

    return interface_list;
}

std::shared_ptr<pcappp::IPcapInterface> pcappp::Pcap::FindInterfaceByDescription(std::string const &description)
{
    std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> interfaces = FindInterfaces();
    for (std::shared_ptr<pcappp::IPcapInterface> &interface_ : *interfaces)
    {
        if (interface_->Description() == description)
        {
            return interface_;
        }
    }

    return nullptr;
}

std::shared_ptr<pcappp::IPcapInterface> pcappp::Pcap::FindInterfaceByName(std::string const &name)
{
    std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> interfaces = FindInterfaces();
    for (std::shared_ptr<pcappp::IPcapInterface> &interface_ : *interfaces)
    {
        if (interface_->Name() == name)
        {
            return interface_;
        }
    }

    return nullptr;
}

void pcappp::Pcap::PrintInterfacesDescriptions()
{
    std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> interfaces = FindInterfaces();
    for (std::shared_ptr<pcappp::IPcapInterface> &interface_ : *interfaces)
    {
        std::cout << interface_->Description() << std::endl;
    }
}

void pcappp::Pcap::PrintInterfacesNames()
{
    std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> interfaces = FindInterfaces();
    for (std::shared_ptr<pcappp::IPcapInterface> &interface_ : *interfaces)
    {
        std::cout << interface_->Name() << std::endl;
    }
}
