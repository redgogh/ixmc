cmake_minimum_required(VERSION 3.26)
project(ixmc)

set(CMAKE_CXX_STANDARD 23)

include_directories(SYSTEM include)

file(GLOB SOURCES
  "*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
