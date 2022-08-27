#include "equation.h"
#include "test.h"
#include <stdio.h>
#include <TXLib.h>

int solveSquareEquation (double coef_a, double coef_b, double coef_c, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);

    if (isZero (coef_a))
        return linEquationSolver (coef_b, coef_c, x1);

    else
        return squareEquationSolver (coef_a, coef_b, coef_c, x1, x2);
}

// doxygen code documentation

int linEquationSolver (double coef_b, double coef_c, double *x1)
{
    ASSERT(x1 != NULL);
    if (isZero (coef_b))
    {
        if (isZero (coef_c))
            return -1;

        else
            return 0;
    }

    *x1 = -coef_c / coef_b;

    if (isZero(*x1))
        *x1 = 0;

    return 1;
}

static int squareEquationSolver (double coef_a, double coef_b, double coef_c, double *x1, double *x2)
{
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);
    ASSERT(!isZero (coef_a));

    double discr = coef_b * coef_b - 4 * coef_a * coef_c;

    if (isZero (coef_b))
    {                               //isZero для equation
        if (isZero (coef_c))
        {
            *x1 = 0;
            return OneRoot;
        }
        else
        if ((coef_c > 0 && coef_a > 0) || (coef_c < 0 && coef_a <0))
            return NoRoots;

        else
            *x1 = -sqrt (-coef_c / coef_a);
            *x2 =  sqrt (-coef_c / coef_a);

            if (*x1 > *x2)
                ascendingRoots (x1, x2);

            return TwoRoots;
    }

    else
    if (isZero (coef_c))
    {
        *x1 = 0;
        *x2 = -coef_b / coef_a;

        if (*x1 > *x2)
            ascendingRoots (x1, x2);

        return TwoRoots;
    }

    else
    if (isZero (discr))
    {
        *x1 = -coef_b / (2 * coef_a);

        return OneRoot;
    }

    else
    if (discr > 0)
    {
        discr = sqrt (discr);
        coef_a *= 2;
        *x1 = ( -coef_b + discr ) / coef_a;
        *x2 = ( -coef_b - discr ) / coef_a;

        if (*x1 > *x2)
            ascendingRoots (x1, x2);

        return TwoRoots;
    }

    else /*(discr < 0)*/
        return NoRoots;
}

void ascendingRoots (double *x1, double *x2)
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
    double border = 1e-8;
    if (fabs (numIsZero) < border)
        return 1;
    return 0;
}



















