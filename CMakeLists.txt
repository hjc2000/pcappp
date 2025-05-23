cmake_minimum_required(VERSION 3.8)

if(1)
	get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
	set(ProjectName "${CURRENT_DIR_NAME}")

	include($ENV{cpp_lib_build_scripts_path}/cmake-module/setup.cmake)

	project(${ProjectName})
	enable_language(ASM)
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_C_STANDARD 17)
endif()


# 编译为动态库
add_library(${ProjectName} STATIC)
target_import_src(${ProjectName})
target_import_base(${ProjectName} PUBLIC)
target_import_npcap(${ProjectName} PUBLIC)

# 添加测试程序
if(1)
	add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
	target_link_libraries(test ${ProjectName})

	install(TARGETS test
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib)
endif()
