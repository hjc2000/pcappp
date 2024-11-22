#include <format>
#include <iostream>
#include <pcappp/Pcap.h>

int main()
{
    std::cout << pcappp::Pcap::Version() << std::endl;
    std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> interface_list = pcappp::Pcap::FindInterfaces();
    for (std::shared_ptr<pcappp::IPcapInterface> &interface_ : *interface_list)
    {
        std::cout << interface_->ToString() << std::endl;
    }

    for (std::shared_ptr<pcappp::IPcapInterface> &interface_ : *interface_list)
    {
        for (std::shared_ptr<pcappp::IPcapAddress> const &address : interface_->Addresses())
        {
            std::cout << *address->Address() << std::endl;
        }
    }

    return 0;
}
