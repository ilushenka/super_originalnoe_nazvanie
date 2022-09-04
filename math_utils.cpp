#include "equation.h"
#include "math_utils.h"
#include "math.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>

void swapIfGreater (double *x1, double *x2)
{
        ASSERT(x1 != NULL);
        ASSERT(x2 != NULL);
        ASSERT(x1 != x2);

        double temp = *x1;
        *x1 = *x2;
        *x2 = temp;
}

bool isZero (double numIsZero)
{
    double epsilon = 1e-8;

    if (fabs (numIsZero) < epsilon)
    {
        numIsZero = 0;
        return 1;
    }

    return 0;
}
