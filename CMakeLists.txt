cmake_minimum_required(VERSION 3.0.0)

project(cppTest VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 11)

add_executable(cppTest
    helloWorld.cpp 
    problems/printCombinationsOfWordsFromDigitsOnPhone/combinations.cpp
    problems/parantheses/parans.cpp
    problems/LRU/LRU.cpp
    problems/nextPermutation/nextPermutation.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
