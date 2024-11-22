#pragma once
#include <base/net/IPAddress.h>
#include <pcap/pcap.h>

namespace pcappp
{
    base::IPAddress ToIPAddress(sockaddr const &addr);
}
