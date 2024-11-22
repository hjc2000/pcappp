#pragma once
#include <base/net/EndPoint.h>
#include <memory>

namespace pcappp
{
    class IPcapAddress
    {
    public:
        virtual std::shared_ptr<base::EndPoint> Address() const = 0;
        virtual std::shared_ptr<base::EndPoint> NetMask() const = 0;
        virtual std::shared_ptr<base::EndPoint> BroadcastAddress() const = 0;
        virtual std::shared_ptr<base::EndPoint> DestinationAddress() const = 0;
    };
} // namespace pcappp
