# CMakeList.txt : CMake project for EveDataRetriever, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(EveDataRetriever)

find_path(CPPRESTSDK_INCLUDE_DIR cpprest/http_client.h)
include_directories(${CPPRESTSDK_INCLUDE_DIR})

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# For Windows, the cpprest library directory appears to have the version number attached to it.
find_library(CPPRESTSDK_LIBRARY cpprest)
link_libraries(${CPPRESTSDK_LIBRARY})

# Add source to this project's executable.
add_executable (EveDataRetriever "EveDataRetriever.cpp" "EveDataRetriever.h")
