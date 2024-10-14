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
    };
} // namespace pcappp
