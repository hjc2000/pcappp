#pragma once
#include <base/string/Json.h>
#include <string>

namespace pcappp
{
    /// @brief pcap 网络接口的接口类。
    class IPcapInterface :
        public base::IJsonSerializable
    {
    public:
        /// @brief 接口名
        /// @return
        virtual std::string Name() const = 0;

        /// @brief 描述信息
        /// @return
        virtual std::string Description() const = 0;

        base::Json ToJson() override;
    };
} // namespace pcappp
