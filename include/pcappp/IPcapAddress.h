#pragma once
#include <memory>
#include <pcappp/ISocketAddress.h>

namespace pcappp
{
    class IPcapAddress
    {
    public:
        virtual std::shared_ptr<ISocketAddress> Address() const = 0;
        virtual std::shared_ptr<ISocketAddress> NetMask() const = 0;
        virtual std::shared_ptr<ISocketAddress> BroadcastAddress() const = 0;
        virtual std::shared_ptr<ISocketAddress> DestinationAddress() const = 0;
    };
} // namespace pcappp
