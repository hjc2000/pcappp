#include <format>
#include <iostream>
#include <pcappp/Pcap.h>

int main()
{
    std::cout << pcappp::Pcap::Version() << std::endl;
    std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> interface_list = pcappp::Pcap::FindInterfaces();
    for (std::shared_ptr<pcappp::IPcapInterface> &interface_ : *interface_list)
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
