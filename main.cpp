#include <iostream>
#include <pcap/pcap.h>
#include <pcappp/Pcap.h>
#include <pcappp/PcapInterfaceList.h>

int main()
{
    std::cout << net::Pcap::Version() << std::endl;
    auto interfeces = net::PcapInterfaceList::FindInterfaces();
}
