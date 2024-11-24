#include "CaptureResult.h"

pcappp::CaptureResult::CaptureResult(pcap_pkthdr packet_infos, uint8_t *buffer, int buffer_size)
{
    _timestamp = std::chrono::seconds{packet_infos.ts.tv_sec} +
                 std::chrono::microseconds{packet_infos.ts.tv_usec};

    _capture_length = packet_infos.caplen;
    _packet_length = packet_infos.len;
    _buffer = buffer;
    _buffer_size = buffer_size;
}

std::chrono::microseconds pcappp::CaptureResult::Timestamp() const
{
    return _timestamp;
}

int32_t pcappp::CaptureResult::CaptureLength() const
{
    return _capture_length;
}

int32_t pcappp::CaptureResult::PacketLength() const
{
    return _packet_length;
}

base::Span pcappp::CaptureResult::Buffer() const
{
    return base::Span{_buffer, _buffer_size};
}
