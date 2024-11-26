#include "IPcapInterface.h"

base::Json pcappp::IPcapInterface::ToJson() const
{
    base::Json ret{
        {"Name", Name()},
        {"Description", Description()},
    };

    return ret;
}

std::string base::ToString(pcappp::LinkTypes value)
{
    switch (value)
    {
    case pcappp::LinkTypes::LINKTYPE_NULL:
        {
            return "LINKTYPE_NULL";
        }
    case pcappp::LinkTypes::LINKTYPE_ETHERNET:
        {
            return "LINKTYPE_ETHERNET";
        }
    case pcappp::LinkTypes::LINKTYPE_EXP_ETHERNET:
        {
            return "LINKTYPE_EXP_ETHERNET";
        }
    case pcappp::LinkTypes::LINKTYPE_AX25:
        {
            return "LINKTYPE_AX25";
        }
    case pcappp::LinkTypes::LINKTYPE_PRONET:
        {
            return "LINKTYPE_PRONET";
        }
    case pcappp::LinkTypes::LINKTYPE_CHAOS:
        {
            return "LINKTYPE_CHAOS";
        }
    case pcappp::LinkTypes::LINKTYPE_IEEE802_5:
        {
            return "LINKTYPE_IEEE802_5";
        }
    case pcappp::LinkTypes::LINKTYPE_ARCNET_BSD:
        {
            return "LINKTYPE_ARCNET_BSD";
        }
    case pcappp::LinkTypes::LINKTYPE_SLIP:
        {
            return "LINKTYPE_SLIP";
        }
    case pcappp::LinkTypes::LINKTYPE_PPP:
        {
            return "LINKTYPE_PPP";
        }
    case pcappp::LinkTypes::LINKTYPE_FDDI:
        {
            return "LINKTYPE_FDDI";
        }
    case pcappp::LinkTypes::LINKTYPE_PPP_HDLC:
        {
            return "LINKTYPE_PPP_HDLC";
        }
    case pcappp::LinkTypes::LINKTYPE_PPP_ETHER:
        {
            return "LINKTYPE_PPP_ETHER";
        }
    case pcappp::LinkTypes::LINKTYPE_IEEE802_11:
        {
            return "LINKTYPE_IEEE802_11";
        }
    case pcappp::LinkTypes::LINKTYPE_IPV4:
        {
            return "LINKTYPE_IPV4";
        }
    case pcappp::LinkTypes::LINKTYPE_IPV6:
        {
            return "LINKTYPE_IPV6";
        }
    default:
        {
            return "未知或者暂不支持识别的链路层类型";
        }
    }
}
