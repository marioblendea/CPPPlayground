cmake_minimum_required(VERSION 3.0.0)

# Download and unpack googletest at configure time
configure_file(CmakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()


project(cppPlaygroud VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 11)

add_executable(cppPlayground
    playground.cpp 
    problems/printCombinationsOfWordsFromDigitsOnPhone/combinations.cpp
    problems/parantheses/parans.cpp
    problems/LRU/LRU.cpp
    problems/nextPermutation/nextPermutation.cpp
    problems/findSubsequences/findSubsequences.cpp
    problems/findSubsequences/findSubsequences.test.cpp
    problems/findAllWaysToForNumber/findAllWaysToFormNUmber.test.cpp
    problems/largestNumberFrom2Arrays/largestNumberFrom2Arrays.test.cpp
    problems/ToeplitzMatrix/ToeplitzMatrix.test.cpp
    problems/leastBricks/leastBricks.test.cpp
)

# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(cppPlayground gtest_main)
add_test(NAME cppTest_test COMMAND cppTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
