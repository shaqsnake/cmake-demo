#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#ifdef HAVE_SQRT
#include <math.h>
#else
#include <MathFunc.hpp>
#endif

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // Show version info
        printf("%s Verion %d.%d\n", argv[0], Demo_VERSION_MAJOR, Demo_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }

    double inputValue = atof(argv[1]);
#ifdef HAVE_SQRT
    printf("Using the std lib...\n");
    double outputValue = sqrt(inputValue);
#else
    printf("Using my math lib...\n");
    double outputValue = squareRoot(inputValue);
#endif
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}