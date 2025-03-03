#pragma once
#include <base/net/IEndPoint.h>
#include <base/string/Json.h>
#include <memory>

namespace pcappp
{
	class IPcapAddress :
		public base::IJsonSerializable
	{
	public:
		virtual std::shared_ptr<base::IEndPoint> Address() const = 0;
		virtual std::shared_ptr<base::IEndPoint> NetMask() const = 0;
		virtual std::shared_ptr<base::IEndPoint> BroadcastAddress() const = 0;
		virtual std::shared_ptr<base::IEndPoint> DestinationAddress() const = 0;

		/// @brief 序列化为 json
		/// @return
		virtual base::Json ToJson() const = 0;
	};
} // namespace pcappp
