#pragma once
#include <pcap/pcap.h>
#include <pcappp/ISocketAddress.h>

namespace pcappp
{
    class SocketAddress :
        public pcappp::ISocketAddress
    {
    private:
        uint16_t _sa_family{};
        base::Array<uint8_t, 14> _sa_data{};

    public:
        SocketAddress(sockaddr const *addr)
            : _sa_family(addr->sa_family),
              _sa_data(reinterpret_cast<uint8_t const *>(addr->sa_data), 0, 14)
        {
        }

        uint16_t SaFamily() const override
        {
            return _sa_family;
        }

        base::Array<uint8_t, 14> const &SaData() const override
        {
            return _sa_data;
        }
    };
} // namespace pcappp
