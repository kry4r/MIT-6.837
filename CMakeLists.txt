cmake_minimum_required(VERSION 3.25)
project(assignment)

set(CMAKE_CXX_STANDARD 11)
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
        2/light.h
        2/plane.cpp
        2/plane.h
        2/triangle.cpp
        2/triangle.h
        2/transform.cpp
        2/transform.h)


set_target_properties(A2 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/A2"
        OUTPUT_NAME "raytracer")


#A3
FIND_PACKAGE(OpenGL)
set(LIB_SOURCE
        "C:/software/CLion 2023.1.3/bin/mingw/x86_64-w64-mingw32/lib/libfreeglut.dll.a"
        "C:/software/CLion 2023.1.3/bin/mingw/x86_64-w64-mingw32/lib/libfreeglut_static.a"
        "C:/software/CLion 2023.1.3/bin/mingw/x86_64-w64-mingw32/lib/libglu32.a")

add_executable(A3
        3/main.cpp
        3/matrix.cpp
        3/image.cpp
        3/sphere.cpp
        3/raytracer.cpp
        3/camera.cpp
        3/group.cpp
        3/plane.cpp
        3/triangle.cpp
        3/transform.cpp
        3/commandLineArgs.cpp
        3/scene_parser.cpp
        3/light.cpp
        3/glCanvas.cpp
        3/material.cpp)

set_target_properties(A3 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/A3"
        OUTPUT_NAME "raytracer")

target_link_libraries(A3 ${OPENGL_gl_LIBRARY} ${LIB_SOURCE})
