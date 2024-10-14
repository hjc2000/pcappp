#include "Pcap.h"
#include <PcapInitializer.h>

std::string pcappp::Pcap::Version()
{
    pcappp::PcapInitializer::Initialize();
    return std::string{pcap_lib_version()};
}
