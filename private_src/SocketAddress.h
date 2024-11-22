#pragma once
#include <convert.h>
#include <format>
#include <iostream>
#include <pcap/pcap.h>
#include <pcappp/ISocketAddress.h>

namespace pcappp
{
    /// @brief 套接字地址
    class SocketAddress :
        public pcappp::ISocketAddress
    {
    private:
        uint16_t _sa_family{};
        base::Array<uint8_t, 14> _sa_data{};

    public:
        /// @brief 会将 addr 指向的对象的字段深拷贝到本对象中。
        /// @param addr
        SocketAddress(sockaddr const &addr)
            : _sa_family(addr.sa_family),
              _sa_data(reinterpret_cast<uint8_t const *>(addr.sa_data), 0, 14)
        {
            try
            {
                base::IPAddress ip = pcappp::ToIPAddress(addr);
                std::cout << ip << std::endl;
            }
            catch (std::exception const &e)
            {
                std::cout << std::format("error, family = {}", addr.sa_family) << std::endl;
            }
        }

        uint16_t SaFamily() const override
        {
            return _sa_family;
        }

        base::Array<uint8_t, 14> const &SaData() const override
        {
            return _sa_data;
        }

        /// @brief 将本对象强制转换为 sockaddr。
        /// @note 每次调用都会构造一个新的 sockaddr，将本对象的数据拷贝到该 sockaddr 中。
        explicit operator sockaddr() const;
    };
} // namespace pcappp
