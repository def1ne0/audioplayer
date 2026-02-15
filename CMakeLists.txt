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
        Multimedia
        REQUIRED)

add_executable(audioplayer
        main.cpp
        src/MainWindow.cpp
        src/MainWindow.h
        src/AudioPlayer/AudioPlayer.cpp
        src/AudioPlayer/AudioPlayer.h
)
target_link_libraries(audioplayer
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Multimedia
)

