#pragma once
#include <base/net/IPAddress.h>
#include <pcap/pcap.h>

namespace pcappp
{
    /// @brief 将 sockaddr 转化为 base::IPAddress.
    /// @param addr
    /// @return
    base::IPAddress ToIPAddress(sockaddr const &addr);
} // namespace pcappp
