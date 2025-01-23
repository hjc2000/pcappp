#pragma once
#include <base/container/iterator/IEnumerable.h>
#include <memory>
#include <pcap/pcap.h>

namespace pcappp
{
	/// @brief 网络接口集合
	class PcapInterfaceCollection :
		public base::IEnumerable<pcap_if_t *>
	{
	private:
		/// @brief 网络接口集合
		/// @param interfece_link_list 从 pcap 库的 pcap_findalldevs_ex 函数那里得到的设备链表头节点。
		PcapInterfaceCollection(pcap_if_t *interfece_link_list);

		/// @brief 网络接口设备链表头节点。
		std::shared_ptr<pcap_if_t> _interface_link_list_head_node = nullptr;

	public:
		/// @brief 查找设备。
		/// @return 返回设备列表。
		static std::shared_ptr<PcapInterfaceCollection const> FindInterfaces();

		/// @brief 获取迭代器
		/// @return
		std::shared_ptr<base::IEnumerator<pcap_if_t *>> GetEnumerator() override;
	};
} // namespace pcappp
