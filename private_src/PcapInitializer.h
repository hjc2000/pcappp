#pragma once
#include <atomic>
#include <mutex>
#include <pcap/pcap.h>
#include <stdexcept>
#include <string>

namespace pcappp
{
	/// @brief 初始化器
	class PcapInitializer
	{
	private:
		PcapInitializer() = default;

		inline static std::mutex _lock;
		inline static std::atomic_bool _initialized = false;

	public:
		/// @brief 执行初始化
		/// @note 本函数幂等且线程安全。
		static void Initialize();
	};
} // namespace pcappp
