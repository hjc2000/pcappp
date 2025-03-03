#pragma once
#include <base/net/IEndPoint.h>
#include <base/net/IPAddress.h>
#include <memory>
#include <pcap/pcap.h>

namespace pcappp
{
	/// @brief 将 sockaddr 转化为 base::IEndPoint.
	/// @param addr
	/// @return
	std::shared_ptr<base::IEndPoint> ToEndPoint(sockaddr const &addr);
} // namespace pcappp
