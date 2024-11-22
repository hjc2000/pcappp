#include "convert.h"
#include <base/bit/BitConverter.h>
#include <stdexcept>

base::IPAddress pcappp::ToIPAddress(sockaddr const &addr)
{
    switch (addr.sa_family)
    {
    case AF_UNIX:
        {
            break;
        }
    case AF_INET:
        {
            sockaddr_in const *in_addr = reinterpret_cast<sockaddr_in const *>(&addr);
            base::Array<uint8_t, 4> buffer{};

            std::copy(reinterpret_cast<uint8_t const *>(&in_addr->sin_addr.s_addr),
                      reinterpret_cast<uint8_t const *>(&in_addr->sin_addr.s_addr) + 4,
                      buffer.Buffer());

            return base::IPAddress{std::endian::big, buffer};
        }
    case AF_IMPLINK:
        {
            break;
        }
    case AF_PUP:
        {
            break;
        }
    case AF_CHAOS:
        {
            break;
        }
    case AF_NS: // AF_IPX
        {
            /* win 头文件中有一句：
             * 		#define AF_IPX AF_NS
             * 所以如果 define 被传入了 AF_IPX 也是进入这个块中
             */
            break;
        }
    case AF_ISO: // AF_OSI
        {
            break;
        }
    case AF_ECMA:
        {
            break;
        }
    case AF_DATAKIT:
        {
            break;
        }
    case AF_CCITT:
        {
            break;
        }
    case AF_SNA:
        {
            break;
        }
    case AF_DECnet:
        {
            break;
        }
    case AF_DLI:
        {
            break;
        }
    case AF_LAT:
        {
            break;
        }
    case AF_HYLINK:
        {
            break;
        }
    case AF_APPLETALK:
        {
            break;
        }
    case AF_NETBIOS:
        {
            break;
        }
    case AF_VOICEVIEW:
        {
            break;
        }
    case AF_FIREFOX:
        {
            break;
        }
    case AF_UNKNOWN1:
        {
            break;
        }
    case AF_BAN:
        {
            break;
        }
    case AF_ATM:
        {
            break;
        }
    case AF_INET6:
        {
            sockaddr_in6 const *in_addr = reinterpret_cast<sockaddr_in6 const *>(&addr);
            base::Array<uint8_t, 16> buffer{};

            std::copy(reinterpret_cast<uint8_t const *>(&in_addr->sin6_addr.s6_addr),
                      reinterpret_cast<uint8_t const *>(&in_addr->sin6_addr.s6_addr) + 16,
                      buffer.Buffer());

            return base::IPAddress{std::endian::big, buffer};
        }
    case AF_CLUSTER:
        {
            break;
        }
    case AF_12844:
        {
            break;
        }
    case AF_IRDA:
        {
            break;
        }
    case AF_NETDES:
        {
            break;
        }
    case AF_TCNPROCESS:
        {
            break;
        }
    case AF_TCNMESSAGE:
        {
            break;
        }
    case AF_ICLFXBM:
        {
            break;
        }
    case AF_BTH:
        {
            break;
        }
    case AF_MAX:
        {
            break;
        }
    }

    throw std::runtime_error{"暂不支持该类型的地址的转换"};
}

base::IPEndPoint pcappp::ToIPEndPoint(sockaddr const &addr)
{
    switch (addr.sa_family)
    {
    case AF_UNIX:
        {
            break;
        }
    case AF_INET:
        {
            sockaddr_in const *in_addr = reinterpret_cast<sockaddr_in const *>(&addr);
            base::Array<uint8_t, 4> buffer{};

            std::copy(reinterpret_cast<uint8_t const *>(&in_addr->sin_addr.s_addr),
                      reinterpret_cast<uint8_t const *>(&in_addr->sin_addr.s_addr) + 4,
                      buffer.Buffer());

            base::IPAddress ip{std::endian::big, buffer};
            return base::IPEndPoint{ip, in_addr->sin_port};
        }
    case AF_IMPLINK:
        {
            break;
        }
    case AF_PUP:
        {
            break;
        }
    case AF_CHAOS:
        {
            break;
        }
    case AF_NS: // AF_IPX
        {
            /* win 头文件中有一句：
             * 		#define AF_IPX AF_NS
             * 所以如果 define 被传入了 AF_IPX 也是进入这个块中
             */
            break;
        }
    case AF_ISO: // AF_OSI
        {
            break;
        }
    case AF_ECMA:
        {
            break;
        }
    case AF_DATAKIT:
        {
            break;
        }
    case AF_CCITT:
        {
            break;
        }
    case AF_SNA:
        {
            break;
        }
    case AF_DECnet:
        {
            break;
        }
    case AF_DLI:
        {
            break;
        }
    case AF_LAT:
        {
            break;
        }
    case AF_HYLINK:
        {
            break;
        }
    case AF_APPLETALK:
        {
            break;
        }
    case AF_NETBIOS:
        {
            break;
        }
    case AF_VOICEVIEW:
        {
            break;
        }
    case AF_FIREFOX:
        {
            break;
        }
    case AF_UNKNOWN1:
        {
            break;
        }
    case AF_BAN:
        {
            break;
        }
    case AF_ATM:
        {
            break;
        }
    case AF_INET6:
        {
            sockaddr_in6 const *in_addr = reinterpret_cast<sockaddr_in6 const *>(&addr);
            base::Array<uint8_t, 16> buffer{};

            std::copy(reinterpret_cast<uint8_t const *>(&in_addr->sin6_addr.s6_addr),
                      reinterpret_cast<uint8_t const *>(&in_addr->sin6_addr.s6_addr) + 16,
                      buffer.Buffer());

            base::IPAddress ip{std::endian::big, buffer};
            return base::IPEndPoint{ip, in_addr->sin6_port};
        }
    case AF_CLUSTER:
        {
            break;
        }
    case AF_12844:
        {
            break;
        }
    case AF_IRDA:
        {
            break;
        }
    case AF_NETDES:
        {
            break;
        }
    case AF_TCNPROCESS:
        {
            break;
        }
    case AF_TCNMESSAGE:
        {
            break;
        }
    case AF_ICLFXBM:
        {
            break;
        }
    case AF_BTH:
        {
            break;
        }
    case AF_MAX:
        {
            break;
        }
    }

    throw std::runtime_error{"暂不支持该类型的地址的转换"};
}
