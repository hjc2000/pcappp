#pragma once
#include <base/container/Array.h>
#include <cstdint>

namespace pcappp
{
    /// @brief 套接字地址
    class ISocketAddress
    {
    public:
        virtual uint16_t SaFamily() const = 0;
        virtual base::Array<uint8_t, 14> const &SaData() const = 0;
    };
} // namespace pcappp
