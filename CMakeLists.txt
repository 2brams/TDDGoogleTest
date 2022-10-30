cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 14)

project(ExampleGtest LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        58d77fa8070e8cec2dc1ed015d66b454c8d78850 # release-1.12.1
)

FetchContent_MakeAvailable(googletest)
# Set the compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
set(OBJECT_DIR  ${CMAKE_BINARY_DIR}/CMakeFiles/ExampleGtest.dir/src)
message(" -- Object files will be output to ${OBJECT_DIR}")

# Set the sources
set(SOURCES
    src/dummy.cpp
    src/foo.cpp
    test/testDummy.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

include_directories(include)

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p gcoverage
    # COMMAND ${CMAKE_MAKE_PROGRAM} test
    # WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_command(TARGET gcov
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${OBJECT_DIR}
    COMMAND echo "-- Source diretorie: ${CMAKE_BINARY_DIR}/src/"
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/gcoverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
)

add_dependencies(gcov ${PROJECT_NAME})

add_custom_target(lcov
    COMMAND mkdir -p lcoverage
)

add_custom_command(TARGET lcov
    COMMAND echo "=================== LCOV ===================="
    COMMAND echo "-- Passing lcov tool under code coverage"
    COMMAND lcov --capture --directory ${OBJECT_DIR} --output-file lcoverage/main_coverage.info
    COMMAND echo "-- Remove undesired files from main_coverage"
    COMMAND lcov --remove lcoverage/main_coverage.info '*/usr/include/*' '*/gtest/*'
    COMMAND echo "-- Generating HTML output files"
    COMMAND genhtml lcoverage/main_coverage.info --output-directory lcoverage
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES gcoverage)

# Create the gcov-clean target. This cleans the build as well as generated
# .gcda and .gcno files.
add_custom_target(refrech
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm CMakeCache.txt
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)