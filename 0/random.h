//
// Created by Nidhogg on 2024/2/7.
//

#ifndef ASSIGNMENT_RANDOM_H
#define ASSIGNMENT_RANDOM_H
#include <stdlib.h>

#define m 0x100000000LL
#define c 0xB16
#define a 0x5DEECE66DLL

static unsigned long long seed = 1;

double drand48(void)
{
    seed = (a * seed + c) & 0xFFFFFFFFFFFFLL;
    unsigned int x = seed >> 16;
    return 	((double)x / (double)m);

}

void srand48(unsigned int i)
{
    seed  = (((long long int)i) << 16) | rand();
}

#endif //ASSIGNMENT_RANDOM_H
