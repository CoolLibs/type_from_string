cmake_minimum_required(VERSION 3.8)

add_library(type_from_string INTERFACE)
add_library(type_from_string::type_from_string ALIAS type_from_string)
target_compile_features(type_from_string INTERFACE cxx_std_20)
target_include_directories(type_from_string INTERFACE include)