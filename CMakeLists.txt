cmake_minimum_required(VERSION 3.6)
project(StuScore)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES

    listFuncs.cpp
        listFuncs.h
        table.cpp
        table.h
        grades.cpp
  )

add_executable(StuScore ${SOURCE_FILES})