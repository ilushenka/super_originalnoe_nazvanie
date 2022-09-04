#include "equation.h"
#include "math_utils.h"
#include "debug.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static int solveQuadraticEquation (double coef_a, double coef_b, double coef_c, double *x1, double *x2);

int solveLinearEquation (double coef_b, double coef_c, double *x1)
{
    ASSERT(isfinite (coef_b));
    ASSERT(isfinite (coef_c));
    ASSERT(x1 != NULL);

    if (isZero (coef_b))
    {
        if (isZero (coef_c))
            return InfRoots;

        else
            return NoRoots;
    }

    *x1 = -coef_c / coef_b;

    isZero(*x1);

    return OneRoot;
}

static int solveQuadraticEquation (double coef_a, double coef_b, double coef_c, double *x1, double *x2)
{
    ASSERT(isfinite (coef_a));
    ASSERT(isfinite (coef_b));
    ASSERT(isfinite (coef_c));
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);
    ASSERT(!isZero (coef_a));

    double discr = coef_b * coef_b - 4 * coef_a * coef_c;

    if (isZero (coef_b))
    {
        if (isZero (coef_c))
        {
            *x1 = 0;
            return OneRoot;
        }
        if ((coef_c > 0 && coef_a > 0) || (coef_c < 0 && coef_a < 0))
            return NoRoots;
        *x1 = -sqrt (-coef_c / coef_a);
        *x2 = -*x1;

        if (*x1 > *x2)
            swapIfGreater (x1, x2);

        return TwoRoots;
    }
    if (isZero (coef_c))
    {
        *x1 = 0;
        *x2 = -coef_b / coef_a;

        if (*x1 > *x2)
            swapIfGreater (x1, x2);

        return TwoRoots;
    }
    if (isZero (discr))
    {
        *x1 = -coef_b / (2 * coef_a);

        return OneRoot;
    }
    if (discr > 0)
    {
        discr = sqrt (discr);
        coef_a *= 2;
        *x1 = ( -coef_b + discr ) / coef_a;
        *x2 = ( -coef_b - discr ) / coef_a;

        if (*x1 > *x2)
            swapIfGreater (x1, x2);

        return TwoRoots;
    }

    return NoRoots;
}

int solveQuadraticOrLinearEquation (double coef_a, double coef_b, double coef_c, double *x1, double *x2)
{
    ASSERT(isfinite (coef_a));
    ASSERT(isfinite (coef_b));
    ASSERT(isfinite (coef_c));
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);

    if (isZero (coef_a))
        return solveLinearEquation (coef_b, coef_c, x1);

    else
        return solveQuadraticEquation (coef_a, coef_b, coef_c, x1, x2);
}

