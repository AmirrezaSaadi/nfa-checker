cmake_minimum_required(VERSION 3.10)
project(NFA_Checker VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/nfa_loader.cpp
    src/nfa_sim.cpp
)

set(HEADERS
    include/nfa_loader.h
    include/nfa_sim.h
)

add_executable(nfa_checker ${SOURCES} ${HEADERS})

target_include_directories(nfa_checker PRIVATE src include)
