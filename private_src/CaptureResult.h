#pragma once
#include <pcap/pcap.h>
#include <pcappp/ICaptureResult.h>

namespace pcappp
{
    class CaptureResult :
        public pcappp::ICaptureResult
    {
    private:
        std::chrono::microseconds _timestamp;
        int32_t _capture_length = 0;
        int32_t _packet_length = 0;

        /// @brief 捕获到的数据放在此缓冲区
        uint8_t *_buffer = nullptr;

        /// @brief _buffer 的大小。
        int _buffer_size = 0;

    public:
        CaptureResult(pcap_pkthdr packet_infos, uint8_t *buffer, int buffer_size);

        /// @brief 时间戳
        /// @return
        std::chrono::microseconds Timestamp() const override;

        /// @brief 实际捕获长度
        /// @return
        int32_t CaptureLength() const override;

        /// @brief 包的实际长度。
        /// @note 包可能未被完全捕获，实际捕获的长度为 CaptureLength，
        /// 本属性是包的完整长度，CaptureLength 会小于等于本属性.
        /// @return
        int32_t PacketLength() const override;

        /// @brief 捕获到的数据装在这个缓冲区中。
        /// @return
        base::Span Buffer() const override;
    };
} // namespace pcappp
