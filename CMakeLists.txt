cmake_minimum_required(VERSION 3.31)
project(search_engine VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(HEADERS ${CMAKE_SOURCE_DIR}/include)
set(TESTS ${CMAKE_SOURCE_DIR}/tests)
set(SRC ${CMAKE_SOURCE_DIR}/src)
add_subdirectory(tests)
add_subdirectory(nlohmann_json)

add_executable(search_engine
        main.cpp
        ${SRC}/ConverterJSON.cpp
        ${SRC}/InvertedIndex.cpp
        ${SRC}/SearchServer.cpp
        ${HEADERS}/ConverterJSON.h
        ${HEADERS}/InvertedIndex.h
        ${HEADERS}/SearchServer.h)

set(JSON_BuildTests OFF CACHE INTERNAL "")
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
