#include "PcapAddress.h"

pcappp::PcapAddress::PcapAddress(pcap_addr const &addr)
{
    if (addr.addr != nullptr)
    {
        _address = std::shared_ptr<ISocketAddress>{new SocketAddress{*addr.addr}};
    }

    if (addr.netmask != nullptr)
    {
        _netmask = std::shared_ptr<ISocketAddress>{new SocketAddress{*addr.netmask}};
    }

    if (addr.broadaddr != nullptr)
    {
        _broadcast_address = std::shared_ptr<ISocketAddress>{new SocketAddress{*addr.broadaddr}};
    }

    if (addr.dstaddr != nullptr)
    {
        _destination_address = std::shared_ptr<ISocketAddress>{new SocketAddress{*addr.dstaddr}};
    }
}
