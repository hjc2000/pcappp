#include <format>
#include <iostream>
#include <pcappp/Pcap.h>

int main()
{
    std::cout << pcappp::Pcap::Version() << std::endl;
    std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> interface_list = pcappp::Pcap::FindInterfaces();
    std::shared_ptr<pcappp::IPcapInterface> interface_ = pcappp::Pcap::FindInterfaceByDescription("Network adapter 'Intel(R) Wi-Fi 6 AX200 160MHz' on local host");
    if (interface_ != nullptr)
    {
        std::cout << interface_->ToString() << std::endl;
        interface_->Open();
        interface_->CaptureOnePacket();
        if (interface_->CaptureResult().Code() == pcappp::CaptureResultCode::Success)
        {
            std::cout << "捕获成功" << std::endl;
        }
    }

    return 0;
}
