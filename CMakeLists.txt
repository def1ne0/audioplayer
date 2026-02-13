cmake_minimum_required(VERSION 4.1)
project(audioplayer)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,leak,undefined")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(audioplayer
        main.cpp
        src/Counter.h
        src/Counter.cpp
        src/MainWindow.cpp
        src/MainWindow.h
)
target_link_libraries(audioplayer
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

