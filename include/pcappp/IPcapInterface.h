#pragma once
#include <base/container/iterator/IEnumerable.h>
#include <base/string/Json.h>
#include <pcap/dlt.h>
#include <pcappp/ICaptureResult.h>
#include <pcappp/IPcapAddress.h>
#include <string>

namespace pcappp
{
    /// @brief 链路层类型。
    /// @note https://www.tcpdump.org/linktypes.html
    enum class LinkTypes
    {
        /// @brief 没有链路层协议。
        LINKTYPE_NULL = 0,

        /// @brief 以太网。
        LINKTYPE_ETHERNET = 1,
        LINKTYPE_EXP_ETHERNET = 2,
        LINKTYPE_AX25 = 3,
        LINKTYPE_PRONET = 4,
        LINKTYPE_CHAOS = 5,
        LINKTYPE_IEEE802_5 = 6,
        LINKTYPE_ARCNET_BSD = 7,
        LINKTYPE_SLIP = 8,
        LINKTYPE_PPP = 9,
        LINKTYPE_FDDI = 10,
        LINKTYPE_PPP_HDLC = 50,
        LINKTYPE_PPP_ETHER = 51,

        /// @brief 802.11 无线网。
        LINKTYPE_IEEE802_11 = 105,

        /// @brief 没有发现数据链路层协议，直接发现了没有被包在数据链路层帧中的裸的 IPV4 帧。
        LINKTYPE_IPV4 = 228,

        /// @brief 没有发现数据链路层协议，直接发现了没有被包在数据链路层帧中的裸的 IPV6 帧。
        LINKTYPE_IPV6 = 229,
    };

    /// @brief pcap 网络接口的接口类。
    class IPcapInterface :
        public base::IJsonSerializable
    {
    public:
#pragma region 信息
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

        /// @brief 链路层类型。
        /// @return
        virtual pcappp::LinkTypes LinkType() const = 0;
#pragma endregion

        /// @brief 用默认方式打开设备。
        virtual void Open() = 0;

        /// @brief 捕获一个包。
        virtual void CaptureOnePacket() = 0;

        /// @brief 调用 CaptureOnePacket 方法捕获包后从这里读取捕获结果。
        /// @return
        virtual pcappp::ICaptureResult const &CaptureResult() const = 0;
    };
} // namespace pcappp

namespace base
{
    /// @brief 将 pcappp::LinkTypes （链路层类型）转为字符串。
    /// @param value
    /// @return
    std::string ToString(pcappp::LinkTypes value);
} // namespace base
