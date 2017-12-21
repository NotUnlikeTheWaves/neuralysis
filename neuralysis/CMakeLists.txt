cmake_minimum_required(VERSION 2.8.9)
project(neuralysis)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(neuralysis ${SOURCES})

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(neuralysis PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_link_libraries(neuralysis)