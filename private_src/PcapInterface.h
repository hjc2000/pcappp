#pragma once
#include <base/container/List.h>
#include <CaptureResult.h>
#include <pcap/pcap.h>
#include <PcapAddress.h>
#include <PcapInterfaceCollection.h>
#include <pcappp/IPcapInterface.h>

namespace pcappp
{
    /// @brief pcap 网络接口。
    class PcapInterface :
        public pcappp::IPcapInterface
    {
    private:
        std::string _name;
        std::string _description;
        base::List<std::shared_ptr<pcappp::IPcapAddress>> _list;
        std::unique_ptr<char[]> _error_buffer{new char[PCAP_ERRBUF_SIZE]{}};

        /// @brief 打开设备后的句柄
        std::shared_ptr<pcap_t> _handle;
        pcappp::CaptureResult _capture_result;

    public:
        /// @brief
        /// @param interfece_ 被包装的网络接口。
        PcapInterface(pcap_if_t *interfece_);

        /// @brief 接口名
        /// @return
        std::string Name() const override;

        /// @brief 描述信息
        /// @return
        std::string Description() const override;

        /// @brief 迭代设备地址集合。
        /// @return 返回设备地址的可迭代集合的引用。
        base::IEnumerable<std::shared_ptr<pcappp::IPcapAddress>> const &Addresses() const override;

        /// @brief 序列化为 json
        /// @return
        base::Json ToJson() const override;

        /// @brief 用默认方式打开设备。
        void Open() override;

        /// @brief 捕获一个包。
        void CaptureOnePacket() override;

        /// @brief 调用 CaptureOnePacket 方法捕获包后从这里读取捕获结果。
        /// @return
        pcappp::ICaptureResult const &CaptureResult() const override;
    };
} // namespace pcappp
