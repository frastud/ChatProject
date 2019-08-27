add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp MessageTest.cpp ChatTest.cpp ChatListTest.cpp AccountTest.cpp UserTest.cpp ExceptionNotFoundTest.cpp)
add_executable(runChatTests ${TEST_SOURCE_FILES})
target_link_libraries(runChatTests gtest gtest_main core)