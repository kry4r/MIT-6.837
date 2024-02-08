cmake_minimum_required(VERSION 3.25)
project(assignment)

set(CMAKE_CXX_STANDARD 17)
set(OUTPUT_DIR ../bin/)

#A0
add_executable(A0
        0/main.cpp
        0/image.cpp
        0/image.h
        0/matrix.cpp
        0/matrix.h
        0/ifs.cpp
        0/ifs.h 0/random.h)

set_target_properties(A0 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/A0"
        OUTPUT_NAME "ifs")

#A1
add_executable(A1
        1/main.cpp
        1/matrix.cpp
        1/image.cpp
        1/scene_parser.cpp
        1/raytracer.cpp
        1/matrix.cpp
        1/sphere.cpp
        1/sphere.h
        1/group.cpp
        1/group.h
        1/camera.cpp)


set_target_properties(A1 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/A1"
        OUTPUT_NAME "raytracer")


#A2
add_executable(A2
        2/main.cpp
        2/matrix.cpp
        2/image.cpp
        2/scene_parser.cpp
        2/raytracer.cpp
        2/matrix.cpp
        2/sphere.cpp
        2/sphere.h
        2/group.cpp
        2/group.h
        2/camera.cpp
        2/commandLineArgs.cpp
        2/commandLineArgs.h
        2/light.h)


set_target_properties(A1 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/A2"
        OUTPUT_NAME "raytracer")

