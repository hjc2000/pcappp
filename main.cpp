#include <iostream>
#include <pcap/pcap.h>
#include <pcappp/Pcap.h>
#include <pcappp/PcapInterfaceCollection.h>

int main()
{
    std::cout << net::Pcap::Version() << std::endl;
    auto interfeces = net::PcapInterfaceCollection::FindInterfaces();
    for (auto &interface_ : *interfeces)
    {
        std::cout << interface_->name << std::endl;
    }
}
