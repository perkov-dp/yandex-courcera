cmake_minimum_required(VERSION 3.11)

set(PROJECT_NAME "task_solution")
project(${PROJECT_NAME} CXX)
set(CMAKE_CXX_STANDARD 20)
# исполняемый файл поместить в bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
	src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

