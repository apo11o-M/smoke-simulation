project(smoke-simulation)
CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(SFML)
ADD_EXECUTABLE(smoke-simulation Fps.cpp main.cpp)

TARGET_LINK_LIBRARIES(smoke-simulation sfml-graphics sfml-window sfml-system)
