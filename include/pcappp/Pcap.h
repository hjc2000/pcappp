#pragma once
#include <base/container/iterator/IEnumerable.h>
#include <memory>
#include <pcappp/IPcapInterface.h>
#include <string>

namespace pcappp
{
    class Pcap
    {
    public:
        /// @brief 获取版本信息字符串。
        /// @return
        static std::string Version();

        /// @brief 查找网络接口。
        /// @return 返回网络接口的可迭代集合。
        static std::shared_ptr<base::IEnumerable<std::shared_ptr<pcappp::IPcapInterface>>> FindInterfaces();

        /// @brief 通过设备描述查找网络接口。即找到一个接口的 Description 属性等于 description.
        /// @param description
        /// @return
        static std::shared_ptr<pcappp::IPcapInterface> FindInterfaceByDescription(std::string const &description);

        /// @brief 通过设备名找到网络接口。即找到一个接口的 Name 属性等于 name.
        /// @param name
        /// @return
        static std::shared_ptr<pcappp::IPcapInterface> FindInterfaceByName(std::string const &name);
    };
} // namespace pcappp
