#include "PcapAddress.h"
#include <convert.h>

pcappp::PcapAddress::PcapAddress(pcap_addr const &addr)
{
	if (addr.addr != nullptr)
	{
		try
		{
			_address = pcappp::ToEndPoint(*addr.addr);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	if (addr.netmask != nullptr)
	{
		try
		{
			_netmask = pcappp::ToEndPoint(*addr.netmask);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	if (addr.broadaddr != nullptr)
	{
		try
		{
			_broadcast_address = pcappp::ToEndPoint(*addr.broadaddr);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	if (addr.dstaddr != nullptr)
	{
		try
		{
			_destination_address = pcappp::ToEndPoint(*addr.dstaddr);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

base::Json pcappp::PcapAddress::ToJson() const
{
	base::Json root{};
	if (Address() != nullptr)
	{
		root["Address"] = Address()->ToJson();
	}
	if (NetMask() != nullptr)
	{
		root["NetMask"] = NetMask()->ToJson();
	}
	if (BroadcastAddress() != nullptr)
	{
		root["BroadcastAddress"] = BroadcastAddress()->ToJson();
	}
	if (DestinationAddress() != nullptr)
	{
		root["DestinationAddress"] = DestinationAddress()->ToJson();
	}

	return root;
}
