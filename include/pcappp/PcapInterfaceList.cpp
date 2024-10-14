#include "PcapInterfaceList.h"
#include <iostream>
#include <pcappp/PcapInitializer.h>

net::PcapInterfaceList::PcapInterfaceList(pcap_if_t *interfece_link_list_head_node)
{
    net::PcapInitializer::Initialize();
    _interface_link_list_head_node = interfece_link_list_head_node;
    CopyInterfecesToVector();
}

void net::PcapInterfaceList::CopyInterfecesToVector()
{
    pcap_if_t *current_interfece = _interface_link_list_head_node;
    while (true)
    {
        if (current_interfece == nullptr)
        {
            break;
        }

        _interfeces.push_back(current_interfece);
        current_interfece = current_interfece->next;
    }

    std::cout << _interfeces.size() << std::endl;
    for (auto interfece : _interfeces)
    {
        std::cout << interfece->name << std::endl;
    }
}

net::PcapInterfaceList::~PcapInterfaceList()
{
    if (_interface_link_list_head_node != nullptr)
    {
        pcap_freealldevs(_interface_link_list_head_node);
        _interface_link_list_head_node = nullptr;
    }
}

std::shared_ptr<net::PcapInterfaceList const> net::PcapInterfaceList::FindInterfaces()
{
    char error_message_buffer[1024]{};

    pcap_if_t *interfece_link_list_head_node;
    int result = pcap_findalldevs_ex(PCAP_SRC_IF_STRING,
                                     nullptr,
                                     &interfece_link_list_head_node,
                                     error_message_buffer);

    if (result)
    {
        throw std::runtime_error{std::string{error_message_buffer}};
    }

    std::shared_ptr<PcapInterfaceList> list{new PcapInterfaceList{interfece_link_list_head_node}};
    return list;
}
