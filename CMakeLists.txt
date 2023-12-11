cmake_minimum_required(VERSION 3.25)
project(WuZiQi)

set(CMAKE_CXX_STANDARD 23)

add_executable(WuZiQi
        Basic_Logic/Qi_Pan/Qi_Pan.cpp
        main.cpp

        Basic_Logic/Qi_Zi/Qi_Zi.cpp
        Basic_Logic/Game/Game.cpp
        Basic_Logic/Game/Game.h
        Basic_Logic/Qi_Shou/Qi_Shou.cpp
)

# ÃÌº”œ¬√ÊSFML≈‰÷√
set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR D:/softwares/SFML/SFML-2.5.0/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(D:/softwares/SFML/SFML-2.5.0/include)
target_link_libraries(WuZiQi sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
