#pragma once
#include <string>

namespace pcappp
{
    class Pcap
    {
    public:
        /// @brief 获取版本信息字符串。
        /// @return
        static std::string Version();
    };
} // namespace pcappp
