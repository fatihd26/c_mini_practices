cmake_minimum_required(VERSION 3.15)

project(VSCODE_1)

set(CMAKE_C_STANDARD 11)

add_executable(VSCODE_1
    main.c
    components/Node.c
    components/Circuit.c
)
