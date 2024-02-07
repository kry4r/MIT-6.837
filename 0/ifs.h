//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_IFS_H
#define ASSIGNMENT_IFS_H
#include "vectors.h"
#include "matrix.h"
#include "image.h"
#include <vector>

class ifs{
public:
    ifs() = default;
    void readformfile(const std::string &filename);
    void render(Image& img,int pointnum,int iternum);

private:
    int numTrans;
    vector<Matrix> matrix;
    vector<float> prob;
    Matrix& chooseTransform(double transchooser);

};


#endif //ASSIGNMENT_IFS_H
