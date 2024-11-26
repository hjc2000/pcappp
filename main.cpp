#include <format>
#include <iostream>
#include <pcappp/Pcap.h>

int main()
{
    std::cout << pcappp::Pcap::Version() << std::endl;
    std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> interface_list = pcappp::Pcap::FindInterfaces();
    // std::shared_ptr<pcappp::IPcapInterface> interface_ = pcappp::Pcap::FindInterfaceByDescription("Network adapter 'Realtek PCIe GbE Family Controller' on local host");
    std::shared_ptr<pcappp::IPcapInterface> interface_ = pcappp::Pcap::FindInterfaceByDescription("Network adapter 'Intel(R) Wi-Fi 6 AX200 160MHz' on local host");
    if (interface_ != nullptr)
    {
        interface_->Open();
        interface_->CaptureOnePacket();
        if (interface_->CaptureResult().Code() == pcappp::CaptureResultCode::Success)
        {
            std::cout << "success" << std::endl;
        }

        std::cout << interface_->LinkType() << std::endl;
        std::cout << interface_->CaptureResult().Timestamp() << std::endl;
        std::cout << interface_->CaptureResult().CaptureLength() << std::endl;
    }

    return 0;
}
