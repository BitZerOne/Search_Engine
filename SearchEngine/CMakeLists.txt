cmake_minimum_required(VERSION 3.11)

project(SearchEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)


set(HEADERS converterjson.h)

set(SRC  converterjson.cpp main.cpp)

add_executable(SearchEngine ${HEADERS} ${SRC})

target_link_libraries(SearchEngine PRIVATE nlohmann_json::nlohmann_json)
