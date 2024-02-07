//
// Created by Nidhogg on 2024/2/7.
//

#include <cstring>
#include <cassert>
#include <cstdio>

#include "image.h"
#include "raytracer.h"

int main(int argc, char* argv[]) {
    char *input_file = nullptr;
    int width = 100;
    int height = 100;
    char *output_file = nullptr;
    float depth_min = 0;
    float depth_max = 1;
    char *depth_file = nullptr;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i],"-input")) {
            i++; assert (i < argc);
            input_file = argv[i];
        } else if (!strcmp(argv[i],"-size")) {
            i++; assert (i < argc);
            width = atoi(argv[i]);
            i++; assert (i < argc);
            height = atoi(argv[i]);
        } else if (!strcmp(argv[i],"-output")) {
            i++; assert (i < argc);
            output_file = argv[i];
        } else if (!strcmp(argv[i],"-depth")) {
            i++; assert (i < argc);
            depth_min = atof(argv[i]);
            i++; assert (i < argc);
            depth_max = atof(argv[i]);
            i++; assert (i < argc);
            depth_file = argv[i];
        } else {
            printf ("whoops error with command line argument %d: '%s'\n",i,argv[i]);
            assert(0);
        }
    }

    auto img = Image(width, height);
    RayTracer rayTracer;
    rayTracer.readSceneFromFile(input_file);
    rayTracer.renderToImage(img);
    img.SaveTGA(output_file);

    rayTracer.renderDepthToImage(img, depth_min, depth_max);
    img.SaveTGA(depth_file);
}