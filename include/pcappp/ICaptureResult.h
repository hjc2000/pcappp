#pragma once
#include <base/stream/ReadOnlySpan.h>
#include <chrono>
#include <cstdint>
#include <pcap/dlt.h>

namespace pcappp
{
    enum class CaptureResultCode
    {
        Success,
        Timeout,
        Error,
    };

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

    /// @brief 捕获结果。因为捕获缓冲区由 npcap 管理，并且只有 1 个，
    /// 所以本接口实例应该储存在网络接口对象中，一个网络接口储存一个本接口实例。
    /// 捕获后检查网络接口对象的该实例从而获取捕获结果。
    class ICaptureResult
    {
    public:
        /// @brief 捕获结果代码
        /// @return
        virtual pcappp::CaptureResultCode Code() const = 0;

        /// @brief 时间戳
        /// @return
        virtual std::chrono::microseconds Timestamp() const = 0;

        /// @brief 实际捕获长度
        /// @return
        virtual int32_t CaptureLength() const = 0;

        /// @brief 包的实际长度。
        /// @note 包可能未被完全捕获，实际捕获的长度为 CaptureLength，
        /// 本属性是包的完整长度，CaptureLength 会小于等于本属性。
        /// @return
        virtual int32_t PacketLength() const = 0;

        /// @brief 捕获到的数据装在这个缓冲区中。
        /// @return
        virtual base::ReadOnlySpan Buffer() const = 0;
    };
} // namespace pcappp
