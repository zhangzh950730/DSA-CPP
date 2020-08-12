cmake_minimum_required(VERSION 3.16)
project(C_CPP)

set(CMAKE_CXX_STANDARD 14)

# 遍历项目根目录下所有的 .cpp和.c 文件
#file(GLOB_RECURSE files *.cpp *.c)
file(GLOB files *.cpp */*.cpp */*/*.cpp */*/*/*.cpp *.c */*.c */*/*.c */*/*/*.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()