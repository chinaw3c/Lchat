cmake_minimum_required(VERSION 3.13)
project(Lchat)

set(CMAKE_CXX_STANDARD 14)

LINK_LIBRARIES(pthread)

add_executable(Lchat main.cpp socket/Server.cc socket/Server.h)