cmake_minimum_required(VERSION 3.15)

project(VSCODE_1)

set(CMAKE_C_STANDARD 11)

add_executable(VSCODE_1
    main.c
    src/matrix.c
    src/components/node.c
    src/components/circuit.c
    src/components/resistor.c
    src/solver/equal_resistance.c

    
)
