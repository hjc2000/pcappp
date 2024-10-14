#include <iostream>
#include <pcap/pcap.h>
#include <pcappp/Pcap.h>

int main()
{
    std::cout << pcappp::Pcap::Version() << std::endl;
    auto interface_list = pcappp::Pcap::FindInterfaces();
    for (auto &interface_ : *interface_list)
    {
        std::cout << interface_->Name() << std::endl;
        std::cout << interface_->Description() << std::endl;
    }
}
