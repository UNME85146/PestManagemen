cmake_minimum_required(VERSION 3.15)
project(PestManagement VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准为17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/SourceCode/header)

# 清除错误的 GCC 标志（针对 MSVC）
if(MSVC)
    # 设置 UTF-8 编码
    add_compile_options(/utf-8)
    # 清除 -g 和 -O0 参数（MSVC 不识别）
    foreach(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
        string(REPLACE "-g" "" ${flag_var} "${${flag_var}}")
        string(REPLACE "-O0" "" ${flag_var} "${${flag_var}}")
    endforeach()

    # 设置 MSVC 调试标志
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /Zi /Od /RTC1")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /O2 /Ob2 /DNDEBUG")

    # 禁用编码警告
    add_compile_options(/wd4819)
endif()

# 对于 GCC/Clang 编译器
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()

# 手动列出所有源文件
set(SOURCE_FILES
        # 主程序（main函数所在的文件）
        ${CMAKE_SOURCE_DIR}/create_pest.cpp

        # SourceCode/src 目录下的所有源文件
        ${CMAKE_SOURCE_DIR}/SourceCode/src/Boast.cpp
        ${CMAKE_SOURCE_DIR}/SourceCode/src/BuildGovernance.cpp
        ${CMAKE_SOURCE_DIR}/SourceCode/src/Divorce.cpp
        ${CMAKE_SOURCE_DIR}/SourceCode/src/FindCollegeGirl.cpp
        ${CMAKE_SOURCE_DIR}/SourceCode/src/kick.cpp
        ${CMAKE_SOURCE_DIR}/SourceCode/src/Mute.cpp
        ${CMAKE_SOURCE_DIR}/SourceCode/src/Pest.cpp
        ${CMAKE_SOURCE_DIR}/SourceCode/src/Prostitution.cpp
        ${CMAKE_SOURCE_DIR}/SourceCode/src/RedTemperature.cpp
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# 链接必要的库
target_link_libraries(${PROJECT_NAME})

# 可选：安装目标
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)