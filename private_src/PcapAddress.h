#pragma once
#include <pcap/pcap.h>
#include <pcappp/IPcapAddress.h>
#include <SocketAddress.h>

namespace pcappp
{
    class PcapAddress :
        public pcappp::IPcapAddress
    {
    private:
        std::shared_ptr<ISocketAddress> _address;
        std::shared_ptr<ISocketAddress> _netmask;
        std::shared_ptr<ISocketAddress> _broadcast_address;
        std::shared_ptr<ISocketAddress> _destination_address;

    public:
        PcapAddress(pcap_addr const &addr);

        std::shared_ptr<ISocketAddress> Address() const override
        {
            return _address;
        }

        std::shared_ptr<ISocketAddress> NetMask() const override
        {
            return _netmask;
        }

        std::shared_ptr<ISocketAddress> BroadcastAddress() const override
        {
            return _broadcast_address;
        }

        std::shared_ptr<ISocketAddress> DestinationAddress() const override
        {
            return _destination_address;
        }
    };
} // namespace pcappp
