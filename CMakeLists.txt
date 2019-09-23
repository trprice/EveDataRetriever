# CMakeList.txt : CMake project for EveDataRetriever, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_path(CPPRESTSDK_INCLUDE_DIR cpprest/http_client.h)
include_directories(${CPPRESTSDK_INCLUDE_DIR})

find_library(CPPRESTSDK_LIBRARY cpprest_2_10)
link_libraries(${CPPRESTSDK_LIBRARY})

# Add source to this project's executable.
add_executable (EveDataRetriever "EveDataRetriever.cpp" "EveDataRetriever.h")