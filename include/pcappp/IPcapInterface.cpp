#include "IPcapInterface.h"
#include <format>

std::string pcappp::IPcapInterface::ToString()
{
    return std::format("{}\t({})",
                       Name(),
                       Description());
}
