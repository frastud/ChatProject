cmake_minimum_required(VERSION 3.14)
project(ChatProject)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES Message.cpp Message.h Chat.cpp Chat.h ChatList.cpp ChatList.h)
add_executable(ChatProject main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ChatProject core)