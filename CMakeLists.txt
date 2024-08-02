cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

cmake_minimum_required(VERSION 2.8.10)

set(application_name "ka")
set(executable_name "ka")
project(${application_name})

include_directories(include)

set(
    common_sources
    src/Board.cpp
    src/ColumnPosition.cpp
    src/Deck.cpp
    src/FoundationPosition.cpp
    src/Game.cpp
    src/HandPosition.cpp
    src/Rank.cpp
    src/Suit.cpp
    src/main.cpp
    src/CardColor.cpp
    src/Card.cpp
)
add_library(ka_common ${common_sources})
target_link_libraries (${executable_stem} ka_common)

add_executable(${executable_name} src/main.cpp)
target_link_libraries(${executable_name} ka_common)
