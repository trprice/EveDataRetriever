# CMakeList.txt : CMake project for EveDataRetriever, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(EveDataRetriever)

find_package(cpprestsdk CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (EveDataRetriever "EveDataRetriever.cpp" "EveDataRetriever.h")

# Use C++11
set_target_properties(EveDataRetriever PROPERTIES
	CMAKE_CXX_STANDARD 11
	CMAKE_CXX_STANDARD_REQUIRED YES
	CMAKE_CXX_EXTENSIONS NO
)

# For Windows, the cpprest library directory appears to have the version number attached to it.
#find_library(CPPRESTSDK_LIBRARY cpprest)
#link_libraries(${CPPRESTSDK_LIBRARY})
target_link_libraries(EveDataRetriever PRIVATE cpprestsdk::cpprest cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_boost_internal cpprestsdk::cpprestsdk_brotli_internal)