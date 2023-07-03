# cmake_minimum_required(VERSION 3.0.0)
# project(demo VERSION 0.1.0)

# include(CTest)
# enable_testing()

# add_executable(demo main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.0.0)

# 项目信息
project(a)
set(CMAKE_CXX_COMPILER "g++")
# 指定生成目标，编译a.cpp源程序，生成a.exe的可执行程序
# add_executable(a a.cpp)

# include_directories(
#         ${PROJECT_SOURCE_DIR}/include/
# )
aux_source_directory(
    ./src SrcFiles
)   #将源文件列表写在变量SrcFiles中
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)#设置可执行文件输出路径
add_executable(a ${SrcFiles})#设置可执行文件的名称，在终端mingw32-make之后bin目录下出现a.exe

