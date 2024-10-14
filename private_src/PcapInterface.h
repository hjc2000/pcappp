#pragma once
#include <PcapInterfaceCollection.h>
#include <pcappp/IPcapInterface.h>

namespace pcappp
{
    /// @brief pcap 网络接口。
    class PcapInterface :
        public pcappp::IPcapInterface
    {
    private:
        std::shared_ptr<PcapInterfaceCollection const> _collection = nullptr;
        pcap_if_t *_interfece = nullptr;

    public:
        /// @brief
        /// @param interfece_ 被包装的网络接口。
        /// @param collection 本类需要保持住 interfece_ 所在的集合，否则到时候集合释放了，
        /// 本类就变成引用着野指针 interfece_ 了。
        PcapInterface(pcap_if_t *interfece_,
                      std::shared_ptr<PcapInterfaceCollection const> collection)
        {
            _interfece = interfece_;
            _collection = collection;
        }

        /// @brief 接口名
        /// @return
        std::string Name() const override
        {
            return _interfece->name;
        }

        /// @brief 描述信息
        /// @return
        std::string Description() const override
        {
            return _interfece->description;
        }
    };
} // namespace pcappp
