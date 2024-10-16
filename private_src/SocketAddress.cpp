#include "SocketAddress.h"

pcappp::SocketAddress::operator sockaddr() const
{
    sockaddr ret;
    ret.sa_family = _sa_family;
    _sa_data.CopyTo(0, reinterpret_cast<uint8_t *>(ret.sa_data), 0, 14);
    return ret;
}
