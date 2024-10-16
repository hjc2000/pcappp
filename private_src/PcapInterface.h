#pragma once
#include <base/container/List.h>
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
        base::List<std::shared_ptr<pcappp::ISocketAddress>> _list;

    public:
        /// @brief
        /// @param interfece_ 被包装的网络接口。
        PcapInterface(pcap_if_t *interfece_)
            : _name(interfece_->name),
              _description(interfece_->description)
        {
        }

        /// @brief 接口名
        /// @return
        std::string Name() const override
        {
            return _name;
        }

        /// @brief 描述信息
        /// @return
        std::string Description() const override
        {
            return _description;
        }

        /// @brief 迭代设备地址集合。
        /// @return 返回设备地址的可迭代集合的引用。
        base::IEnumerable<std::shared_ptr<pcappp::ISocketAddress>> const &Addresses() override
        {
            return _list;
        }
    };
} // namespace pcappp
