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


add_executable(A4
        4/main.cpp
        4/matrix.cpp
        4/image.cpp
        4/sphere.cpp
        4/raytracer.cpp
        4/camera.cpp
        4/group.cpp
        4/plane.cpp
        4/triangle.cpp
        4/transform.cpp
        4/commandLineArgs.cpp
        4/scene_parser.cpp
        4/light.cpp
        4/glCanvas.cpp
        4/material.cpp 4/raytree.cpp 4/raytree.h)

set_target_properties(A4 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/A4"
        OUTPUT_NAME "raytracer")

target_link_libraries(A4 ${OPENGL_gl_LIBRARY} ${LIB_SOURCE})
target_compile_options(A4 PUBLIC "-Wno-deprecated-declarations")

#A5

add_executable(A5
        5/main.cpp
        5/matrix.cpp
        5/image.cpp
        5/sphere.cpp
        5/raytracer.cpp
        5/camera.cpp
        5/group.cpp
        5/plane.cpp
        5/triangle.cpp
        5/transform.cpp
        5/commandLineArgs.cpp
        5/scene_parser.cpp
        5/light.cpp
        5/glCanvas.cpp
        5/material.cpp
        5/rayTree.cpp
        5/grid.cpp
        5/boundingbox.cpp
        5/object3d.cpp
        5/hsl.cpp)

set_target_properties(A5 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/A5"
        OUTPUT_NAME "raytracer")

target_link_libraries(A5 ${OPENGL_gl_LIBRARY} ${LIB_SOURCE})

target_compile_options(A5 PUBLIC "-Wno-deprecated-declarations")


add_executable(A6
        6/main.cpp
        6/matrix.cpp
        6/image.cpp
        6/sphere.cpp
        6/raytracer.cpp
        6/camera.cpp
        6/group.cpp
        6/plane.cpp
        6/triangle.cpp
        6/transform.cpp
        6/commandLineArgs.cpp
        6/scene_parser.cpp
        6/light.cpp
        6/glCanvas.cpp
        6/material.cpp
        6/rayTree.cpp
        6/grid.cpp
        6/boundingbox.cpp
        6/object3d.cpp
        6/hsl.cpp
        6/perlin_noise.cpp
        6/raytracing_stats.cpp)

set_target_properties(A6 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/A6"
        OUTPUT_NAME "raytracer")

target_link_libraries(A6 ${OPENGL_gl_LIBRARY} ${LIB_SOURCE})

target_compile_options(A6 PUBLIC "-Wno-deprecated-declarations")