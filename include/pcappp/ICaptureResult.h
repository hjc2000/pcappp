#pragma once
#include <base/stream/ReadOnlySpan.h>
#include <chrono>
#include <cstdint>

namespace pcappp
{
    /// @brief 捕获结果代码。用来指示成功或失败。
    enum class CaptureResultCode
    {
        Success,
        Timeout,
        Error,
    };

    /// @brief 捕获结果。因为捕获缓冲区由 npcap 管理，并且只有 1 个，
    /// 所以本接口实例应该储存在网络接口对象中，一个网络接口储存一个本接口实例。
    /// 捕获后检查网络接口对象的该实例从而获取捕获结果。
    class ICaptureResult
    {
    public:
        /// @brief 捕获结果代码。用来指示成功或失败。
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
