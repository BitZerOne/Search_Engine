cmake_minimum_required(VERSION 3.5)

project(SearchEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(SearchEngine main.cpp)

target_link_libraries(SearchEngine PRIVATE nlohmann_json::nlohmann_json)


