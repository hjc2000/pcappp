#pragma once
#include <pcap/pcap.h>
#include <pcappp/IPcapAddress.h>

namespace pcappp
{
	class PcapAddress :
		public pcappp::IPcapAddress
	{
	private:
		std::shared_ptr<base::IEndPoint> _address;
		std::shared_ptr<base::IEndPoint> _netmask;
		std::shared_ptr<base::IEndPoint> _broadcast_address;
		std::shared_ptr<base::IEndPoint> _destination_address;

	public:
		PcapAddress(pcap_addr const &addr);

		std::shared_ptr<base::IEndPoint> Address() const override
		{
			return _address;
		}

		std::shared_ptr<base::IEndPoint> NetMask() const override
		{
			return _netmask;
		}

		std::shared_ptr<base::IEndPoint> BroadcastAddress() const override
		{
			return _broadcast_address;
		}

		std::shared_ptr<base::IEndPoint> DestinationAddress() const override
		{
			return _destination_address;
		}

		/// @brief 序列化为 json
		/// @return
		base::Json ToJson() const override;
	};
} // namespace pcappp
