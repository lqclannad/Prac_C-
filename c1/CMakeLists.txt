cmake_minimum_required(VERSION 3.19)    # cmake源码
project(Project3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH D:/Tool/opencv_cpp/libtorch-win-shared-with-deps-1.10.0+cpu)
set(OpenCV_DIR D:/Tool/opencv/build)    # opencv的编译路径

find_package(Torch REQUIRED)
find_package(OpenCV REQUIRED)   # 找到使用opencv需要的别的库
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(Project3 test02.cpp)   # 设置要编译的源码
target_link_libraries(Project3 ${TORCH_LIBRARIES} ${OpenCV_LIBS})  # 链接编译时需要的opencv的动态库到当前的项目
set_property(TARGET Project3 PROPERTY CXX_STANDARD 11)

# 将动态链接拷贝到当前程序所在文件夹
if(MSVC)
    file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
    add_custom_command(TARGET Project3
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${TORCH_DLLS}
            $<TARGET_FILE_DIR:Project3>)
    file(GLOB OPENCV_DLLS "D:/Tool/opencv/build/x64/vc15/bin/*.dll")
    add_custom_command(TARGET Project3
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${OPENCV_DLLS}
            $<TARGET_FILE_DIR:Project3>)
endif(MSVC)
