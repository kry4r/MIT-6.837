//
// Created by Nidhogg on 2024/2/7.
//

#include "ifs.h"
#include "random"
#include "random.h"

void ifs::readformfile(const std::string &filename) {
    // open the file
    FILE *input = fopen(filename.c_str(),"r");
    assert(input != NULL);

    // read the number of transforms
    int num_transforms;
    fscanf(input,"%d",&num_transforms);

    numTrans = num_transforms;

    // read in the transforms
    for (int i = 0; i < num_transforms; i++) {
        float probability;
        fscanf (input,"%f",&probability);
        Matrix mt;
        mt.Read3x3(input);
        prob.emplace_back(probability);
        matrix.emplace_back(mt);
    }

    // close the file
    fclose(input);
}


void ifs::render(Image &img, int pointnum, int iternum) {
    Vec3f whiteColor(1.f, 1.f, 1.f), blackColor(0.f, 0.f, 0.f);
    img.SetAllPixels(whiteColor);
    srand48(std::random_device()());
    for (int i = 0; i < pointnum; ++i) {
        float x = drand48(), y = drand48();
        Vec3f pVec(x, y, 1);
        for (int j = 0; j < iternum; ++j) {
            double transChooser = drand48();
            Matrix &tran = chooseTransform(transChooser);
            pVec = tran * pVec;
        }
        int px = pVec.x() / pVec.z() * img.Width();
        int py = pVec.y() / pVec.z() * img.Height();
        if (px < 0 || py < 0 || px >= img.Width() || py >= img.Height())
            continue;
        img.SetPixel(px, py, blackColor);
    }
}

Matrix& ifs::chooseTransform(double transchooser) {
    int index = 0;
    float threshold = 0.0;
    while (true) {
        float newThreshold = threshold + prob[index];
        if (newThreshold > transchooser)
            break;
        threshold = newThreshold;
        ++index;
    }
    assert(index < matrix.size());
    return matrix[index];
}
