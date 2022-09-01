#include "equation.h"
#include "test.h"
#include "math_utils.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// TODO: Definitely just a style. But I would move checkQuadraticOrLinearEquation
//       after definition of both functions (solveQuadraticEquation and solveLinearEquation),
//       and get rid of this forward-declaration.
static int solveQuadraticEquation (double coef_a,     double coef_b,     double coef_c, double *x1, double *x2);
// TODO: Why such weird indentation?              ^~~~               ^~~~

int checkQuadraticOrLinearEquation (double coef_a, double coef_b, double coef_c, double *x1, double *x2)
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

    if (isZero(*x1)) // TODO: Extract in function
        *x1 = 0;

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
        else
    //  ^ TODO: Misleading indentation (stuff inside else is not indented), also else after return
        if ((coef_c > 0 && coef_a > 0) || (coef_c < 0 && coef_a <0))
            return NoRoots;                             // TODO: ^ spaces! are! free! use! them!
        *x1 = -sqrt (-coef_c / coef_a);
        *x2 = -*x1;

        if (*x1 > *x2)
            swapValue (x1, x2);

            return TwoRoots;
        // TODO: Return is not nested in if, misleading indentation
    }
    else // TODO: else after return is considered a bad style by many style guides
    if (isZero (coef_c))
    {
        *x1 = 0;
        *x2 = -coef_b / coef_a;

        if (*x1 > *x2) // TODO: used multiple times, extract in swapIfGreater or something
            swapValue (x1, x2);

        return TwoRoots;
    }
    else // TODO: else after return is considered a bad style by many style guides
    if (isZero (discr))
    {
        *x1 = -coef_b / (2 * coef_a);

        return OneRoot;
    }
    else // TODO: else after return is considered a bad style by many style guides
    if (discr > 0)
    {
        discr = sqrt (discr);
        coef_a *= 2;
        *x1 = ( -coef_b + discr ) / coef_a;
        *x2 = ( -coef_b - discr ) / coef_a;

        if (*x1 > *x2)
            swapValue (x1, x2);

        return TwoRoots;
    }
    else /*(discr < 0)*/ // TODO: else after return is considered a bad style by many style guides
        return NoRoots;
}
