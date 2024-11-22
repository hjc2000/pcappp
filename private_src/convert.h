#pragma once
#include <base/net/IPAddress.h>
#include <base/net/IPEndPoint.h>
#include <pcap/pcap.h>

namespace pcappp
{
    /// @brief 将 sockaddr 转化为 base::IPAddress.
    /// @param addr
    /// @return
    base::IPAddress ToIPAddress(sockaddr const &addr);

    /// @brief 将 sockaddr 转化为 base::IPEndPoint.
    /// @param addr
    /// @return
    base::IPEndPoint ToIPEndPoint(sockaddr const &addr);
} // namespace pcappp
