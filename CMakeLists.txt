cmake_minimum_required(VERSION 3.10)
project(LineServer LANGUAGES CXX)
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}/bin")

# ============================================
# Utils 静态库
# ============================================
file(GLOB_RECURSE UTILS_SOURCES "Source/Utils/src/*.cpp")
file(GLOB_RECURSE UTILS_HEADERS "Source/Utils/include/*.h")

add_library(Utils STATIC
    ${UTILS_SOURCES}
    ${UTILS_HEADERS}
)

target_include_directories(Utils PUBLIC
    Source/Utils/include
)

# ============================================
# LineServer 可执行文件
# ============================================
file(GLOB_RECURSE LINESERVER_SOURCES "Source/LineServer/src/*.cpp")
file(GLOB_RECURSE LINESERVER_HEADERS "Source/LineServer/include/*.h")

add_executable(LineServer
    ${LINESERVER_SOURCES}
    ${LINESERVER_HEADERS}
)

target_include_directories(LineServer PRIVATE
    Source/LineServer/include
    Source/Utils/include
)

target_link_libraries(LineServer PRIVATE Utils)

if(UNIX)
    target_link_libraries(LineServer PRIVATE pthread)
endif()