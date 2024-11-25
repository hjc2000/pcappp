#pragma once
#include <base/container/iterator/IEnumerable.h>
#include <base/string/Json.h>
#include <pcappp/ICaptureResult.h>
#include <pcappp/IPcapAddress.h>
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

        base::Json ToJson() const override;

        /// @brief 迭代设备地址集合。
        /// @return 返回设备地址的可迭代集合的引用。
        virtual base::IEnumerable<std::shared_ptr<pcappp::IPcapAddress>> const &Addresses() const = 0;

        /// @brief 用默认方式打开设备。
        virtual void Open() = 0;

        /// @brief 捕获一个包。
        virtual void CaptureOnePacket() = 0;

        /// @brief 调用 CaptureOnePacket 方法捕获包后从这里读取捕获结果。
        /// @return
        virtual pcappp::ICaptureResult const &CaptureResult() const = 0;
    };
} // namespace pcappp
