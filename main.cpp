#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#ifdef USE_MYMATH
#include "math/MathFunc.hpp"
#else
#include <math.h>
#endif

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }

    double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
    printf("Using my math lib...\n");
    double outputValue = squareRoot(inputValue);
#else
    printf("Using the std lib...\n");
    double outputValue = sqrt(inputValue);
#endif
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}