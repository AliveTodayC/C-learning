cmake_minimum_required(VERSION 3.10)

# 项目信息
project(CppGameLearning)

# 使用 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 设置源文件（你也可以用 file(GLOB ...) 自动找）
set(SOURCES
    src/main.cpp
    src/player.cpp
    "src/team.cpp"
)

# 构建可执行文件
add_executable(CppGame ${SOURCES})
