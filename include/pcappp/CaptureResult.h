#pragma once
#include <chrono>
#include <cstdint>

namespace pcappp
{
    class CaptureResult
    {
    private:
        /// @brief 时间戳
        std::chrono::microseconds _time_stamp;

        /// @brief 实际捕获长度
        int32_t _capture_length = 0;

        /// @brief 包的实际长度。
        /// @note 包可能未被完全捕获，实际捕获的长度为 _capture_length，这里是包的完整长度，
        /// _capture_length 会小于等于 _packet_length.
        int32_t _packet_length = 0;

    public:
    };
} // namespace pcappp
