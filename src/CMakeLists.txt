cmake_minimum_required(VERSION 3.3)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    error.c
    error.h
    lex.yy.c
    main.c
    symNodeType.h
    symtab.c
    symtab.h
    syntax.tab.c
    syntax.tab.h
    tree.c
    tree.h
    util.c
    util.h)

add_executable(src ${SOURCE_FILES})