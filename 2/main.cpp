//
// Created by Nidhogg on 2024/2/7.
//

#include "commandLineArgs.h"
#include "image.h"
#include "raytracer.h"

int main(int argc, char* argv[]) {
    auto cmdlParser = CommandLineArgs();
    cmdlParser.parse(argc, argv);

    auto img = Image(cmdlParser.width, cmdlParser.height);
    RayTracer rayTracer;
    rayTracer.readSceneFromFile(cmdlParser.input_file);
    rayTracer.renderToImage(img, cmdlParser.shade_back);
    img.SaveTGA(cmdlParser.output_file);

    if (cmdlParser.depth_file != nullptr) {
        rayTracer.renderDepthToImage(img, cmdlParser.depth_min, cmdlParser.depth_max);
        img.SaveTGA(cmdlParser.depth_file);
    }

    if (cmdlParser.normal_file != nullptr) {
        rayTracer.renderNormalToImage(img);
        img.SaveTGA(cmdlParser.normal_file);
    }


}