#pragma once
#include <base/net/EndPoint.h>
#include <base/string/Json.h>
#include <memory>

namespace pcappp
{
    class IPcapAddress :
        public base::IJsonSerializable
    {
    public:
        virtual std::shared_ptr<base::EndPoint> Address() const = 0;
        virtual std::shared_ptr<base::EndPoint> NetMask() const = 0;
        virtual std::shared_ptr<base::EndPoint> BroadcastAddress() const = 0;
        virtual std::shared_ptr<base::EndPoint> DestinationAddress() const = 0;

        /// @brief 序列化为 json
        /// @return
        virtual base::Json ToJson() const = 0;
    };
} // namespace pcappp
