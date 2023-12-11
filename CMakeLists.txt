cmake_minimum_required(VERSION 3.25)
project(WuZiQi_New)

set(CMAKE_CXX_STANDARD 23)

add_executable(WuZiQi_New
        Basic_Logic/Qi_Pan/Qi_Pan.cpp
        main.cpp

        Basic_Logic/Qi_Zi/Qi_Zi.cpp
        Basic_Logic/Game/Game.cpp
        Basic_Logic/Game/Game.h
        Basic_Logic/Qi_Zi/Qi_Zi.cpp
        Basic_Logic/Qi_Shou/Qi_Shou.cpp
)


set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(SFML-2.6.1/include)
target_link_libraries(WuZiQi_New sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
