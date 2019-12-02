
cmake_minimum_required(VERSION 3.4.1)

# add_library标签定义我们要生成的动态库(native-lib.so)，动态库的源文件就是后面定义的cpp文件
add_library(
        native-lib
        SHARED
        native-lib.cpp)

add_library(
        dynamic_register
        SHARED
        dynamic_register.cpp)

#查找log库，并将结果赋值给log-lib
find_library(
        log-lib
        log)

#查找到的log-lib的路径链接到我们要编译生成的目标库文件上，这样我们的目标库文件才能链接到具体的函数
target_link_libraries(
        native-lib
        ${log-lib}
)

target_link_libraries(
        dynamic_register
        ${log-lib}
)