#include <format>
#include <iostream>
#include <pcappp/Pcap.h>

int main()
{
    std::cout << pcappp::Pcap::Version() << std::endl;
    auto interface_list = pcappp::Pcap::FindInterfaces();
    for (auto &interface_ : *interface_list)
    {
        std::cout << interface_->ToString() << std::endl;
    }

    for (auto &interface_ : *interface_list)
    {
        for (auto &address : interface_->Addresses())
        {
            std::cout << address->Address()->SaFamily() << std::endl;
        }
    }
}
