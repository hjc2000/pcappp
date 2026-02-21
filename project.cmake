# 编译为动态库
add_library(${ProjectName} OBJECT)
target_import_src(${ProjectName})
target_import_base(${ProjectName} PUBLIC)
target_import_npcap(${ProjectName} PUBLIC)

# 添加测试程序
if(("${platform}" STREQUAL "msys") OR
   ("${platform}" STREQUAL "msys-clang"))
	set(test_exe_target_name "${ProjectName}-test")
	add_executable(${test_exe_target_name})
	target_import_test(${test_exe_target_name})

	target_link_libraries(${test_exe_target_name} PUBLIC ${ProjectName})
endif()
