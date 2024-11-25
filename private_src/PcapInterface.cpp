#include "PcapInterface.h"

pcappp::PcapInterface::PcapInterface(pcap_if_t *interfece_)
    : _name(interfece_->name),
      _description(interfece_->description)
{
    /* 遍历该网络接口的地址链表，取出每一个地址，放到 _list 中。
     * 这是一个深拷贝工作。
     */
    pcap_addr *current_addr_node = interfece_->addresses;
    while (current_addr_node != nullptr)
    {
        std::shared_ptr<pcappp::PcapAddress> pcap_addr{
            new pcappp::PcapAddress{*current_addr_node},
        };

        _list.Add(pcap_addr);
        current_addr_node = current_addr_node->next;
    }
}

#pragma region 信息

std::string pcappp::PcapInterface::Name() const
{
    return _name;
}

std::string pcappp::PcapInterface::Description() const
{
    return _description;
}

base::IEnumerable<std::shared_ptr<pcappp::IPcapAddress>> const &pcappp::PcapInterface::Addresses() const
{
    return _list;
}

base::Json pcappp::PcapInterface::ToJson() const
{
    base::Json root{
        {"Name", Name()},
        {"Description", Description()},
    };

    {
        base::Json addresses_json;
        int i = 0;
        for (std::shared_ptr<pcappp::IPcapAddress> const &address : Addresses())
        {
            addresses_json[i++] = address->ToJson();
        }

        root["Addresses"] = addresses_json;
    }

    return root;
}

#pragma endregion

void pcappp::PcapInterface::Open()
{
    _handle = std::shared_ptr<pcap_t>{
        pcap_open(Name().c_str(),
                  65536,                     // 捕获缓冲区大小
                  PCAP_OPENFLAG_PROMISCUOUS, // promiscuous mode：混杂模式
                  1000,
                  nullptr,
                  _error_buffer.get()),
        [](pcap_t *p)
        {
            // 在删除器中关闭设备
            pcap_close(p);
        },
    };

    if (_handle == nullptr)
    {
        throw std::runtime_error{"打开设备失败"};
    }

    /* 打开设备后的下一步可能会用到的函数
     * pcap_next_ex
     */
}

#pragma region 捕获

void pcappp::PcapInterface::CaptureOnePacket()
{
    pcap_pkthdr *packet_infos = nullptr;
    uint8_t const *buffer = nullptr;

    int result = pcap_next_ex(_handle.get(),
                              &packet_infos,
                              &buffer);

    pcappp::CaptureResultCode result_code = pcappp::CaptureResultCode::Error;
    switch (result)
    {
    case 0:
        {
            // 超时
            result_code = pcappp::CaptureResultCode::Timeout;
            break;
        }
    case PCAP_ERROR:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_BREAK:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_NOT_ACTIVATED:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_ACTIVATED:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_NO_SUCH_DEVICE:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_RFMON_NOTSUP:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_NOT_RFMON:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_PERM_DENIED:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_IFACE_NOT_UP:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_CANTSET_TSTAMP_TYPE:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_PROMISC_PERM_DENIED:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    case PCAP_ERROR_TSTAMP_PRECISION_NOTSUP:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    default:
        {
            result_code = pcappp::CaptureResultCode::Error;
            break;
        }
    };

    _capture_result = pcappp::CaptureResult{
        result_code,
        *packet_infos,
        buffer,
        65536,
    };
}

pcappp::ICaptureResult const &pcappp::PcapInterface::CaptureResult() const
{
    return _capture_result;
}

#pragma endregion
