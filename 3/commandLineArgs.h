//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_COMMANDLINEARGS_H
#define ASSIGNMENT_COMMANDLINEARGS_H

class CommandLineArgumentParser {
public:
    char *input_file = nullptr;
    int width = 100;
    int height = 100;
    char *output_file = nullptr;
    float depth_min = 0;
    float depth_max = 1;
    char *depth_file = nullptr;
    char *normal_file = nullptr;
    bool shade_back = false;
    bool use_gui = false;

    void parse(int argc, char *argv[]);
};

#endif //ASSIGNMENTS_COMMANDLINEARGUMENTPARSER_H
