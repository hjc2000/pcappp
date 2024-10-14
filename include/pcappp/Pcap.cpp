#include "Pcap.h"
#include <PcapInitializer.h>

std::string net::Pcap::Version()
{
    net::PcapInitializer::Initialize();
    return std::string{pcap_lib_version()};
}
