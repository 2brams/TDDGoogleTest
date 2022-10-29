cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 14)

project(ExampleGtest LANGUAGES CXX)

# include_directories(googletest/googletest/include)
# add_executable(${PROJECT_NAME} example.cpp)
# target_link_libraries(${PROJECT_NAME}
#     ${CMAKE_SOURCE_DIR}/googletest/build/lib/libgtest.a
#     ${CMAKE_SOURCE_DIR}/googletest/build/lib/libgtest_main.a
# )
# set(CMAKE_THREAD_LIBS_INIT "-lpthread")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# set(CMAKE_HAVE_THREADS_LIBRARY 1)
# set(CMAKE_USE_WIN32_THREADS_INIT 0)
# set(CMAKE_USE_PTHREADS_INIT 1)
# set(THREADS_PREFER_PTHREAD_FLAG ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        58d77fa8070e8cec2dc1ed015d66b454c8d78850 # release-1.12.1
)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} example.cpp)

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})