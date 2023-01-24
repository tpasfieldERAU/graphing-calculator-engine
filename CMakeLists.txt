cmake_minimum_required(VERSION 3.23)
project(graphing_calculator_engine C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(graphing_calculator_engine
        main.c
        outputs.c outputs.h
        pointGenerators.c pointGenerators.h
        plotters.c plotters.h
        vars.c vars.h)

target_link_libraries(${PROJECT_NAME} m)