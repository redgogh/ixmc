cmake_minimum_required(VERSION 3.26)
project(xmc)

set(CMAKE_CXX_STANDARD 23)

include_directories(SYSTEM include)

file(GLOB SOURCES
  "*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
