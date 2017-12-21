cmake_minimum_required(VERSION 2.8.9)
project(neuralysis-dev-app)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/neuralysis)

add_executable(run_file main.cpp)
target_link_libraries(run_file neuralysis)