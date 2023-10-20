cmake_minimum_required(VERSION 3.26)
project(WuZiQi)

set(CMAKE_CXX_STANDARD 17)

add_executable(WuZiQi main.cpp
        Basic_Logic/Game/Game.cpp
        Basic_Logic/Game/Game.h
        Basic_Logic/Qi_Pan/Qi_Pan.cpp
        Basic_Logic/Qi_Pan/Qi_Pan.h
        Basic_Logic/Qi_Shou/Qi_Shou.cpp
        Basic_Logic/Qi_Shou/Qi_Shou.h
        Basic_Logic/Qi_Zi/Qi_Zi.cpp
        Basic_Logic/Qi_Zi/Qi_Zi.h
)
