#include "CaptureResult.h"

pcappp::CaptureResult::CaptureResult(pcappp::CaptureResultCode result_code,
                                     pcap_pkthdr const &packet_infos,
                                     uint8_t const *buffer,
                                     int buffer_size)
{
    _result_code = result_code;
    _timestamp = std::chrono::seconds{packet_infos.ts.tv_sec} +
                 std::chrono::microseconds{packet_infos.ts.tv_usec};

    _capture_length = packet_infos.caplen;
    _packet_length = packet_infos.len;
    _buffer = buffer;
    _buffer_size = buffer_size;
}

pcappp::CaptureResult::CaptureResult(CaptureResult const &o)
{
    *this = o;
}

pcappp::CaptureResult &pcappp::CaptureResult::operator=(CaptureResult const &o)
{
    _result_code = o._result_code;
    _timestamp = o._timestamp;
    _capture_length = o._capture_length;
    _packet_length = o._packet_length;
    _buffer = o._buffer;
    _buffer_size = o._buffer_size;
    return *this;
}

pcappp::CaptureResultCode pcappp::CaptureResult::Code()
{
    return pcappp::CaptureResultCode();
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

base::ReadOnlySpan pcappp::CaptureResult::Buffer() const
{
    return base::ReadOnlySpan{_buffer, _buffer_size};
}
