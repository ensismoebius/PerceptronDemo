cmake_minimum_required(VERSION 3.5)
project(nn2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2 REQUIRED COMPONENTS graphics system window)
find_package(Threads REQUIRED)

set (SRCS
src/lib/PointsDrawer.cpp
src/lib/Perceptron.cpp
src/lib/functions.cpp
src/lib/random.cpp
src/lib/Point.cpp
src/lib/map.cpp
src/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
set(SFML_LIBS sfml-system sfml-window sfml-graphics)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})

