#pragma once
#include <pcap/pcap.h>
#include <pcappp/IPcapAddress.h>

namespace pcappp
{
    class PcapAddress :
        public pcappp::IPcapAddress
    {
    private:
        std::shared_ptr<base::EndPoint> _address;
        std::shared_ptr<base::EndPoint> _netmask;
        std::shared_ptr<base::EndPoint> _broadcast_address;
        std::shared_ptr<base::EndPoint> _destination_address;

    public:
        PcapAddress(pcap_addr const &addr);

        std::shared_ptr<base::EndPoint> Address() const override
        {
            return _address;
        }

        std::shared_ptr<base::EndPoint> NetMask() const override
        {
            return _netmask;
        }

        std::shared_ptr<base::EndPoint> BroadcastAddress() const override
        {
            return _broadcast_address;
        }

        std::shared_ptr<base::EndPoint> DestinationAddress() const override
        {
            return _destination_address;
        }

        /// @brief 序列化为 json
        /// @return
        base::Json ToJson() const override;
    };
} // namespace pcappp
