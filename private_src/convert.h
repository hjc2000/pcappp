#pragma once
#include <base/net/EndPoint.h>
#include <base/net/IPAddress.h>
#include <memory>
#include <pcap/pcap.h>

namespace pcappp
{
	/// @brief 将 sockaddr 转化为 base::EndPoint.
	/// @param addr
	/// @return
	std::shared_ptr<base::EndPoint> ToEndPoint(sockaddr const &addr);
} // namespace pcappp
