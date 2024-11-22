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

base::Json pcappp::PcapInterface::ToJson() const
{
    base::Json root{
        {"Name", Name()},
        {"Description", Description()},
    };

    base::Json addresses_json;
    int i = 0;
    for (std::shared_ptr<pcappp::IPcapAddress> const &address : Addresses())
    {
        addresses_json[i++] = address->ToJson();
    }

    root["Addreses"] = addresses_json;
    return root;
}
