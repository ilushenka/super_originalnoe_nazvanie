#include "work_with_user.h"
#include "equation.h"
#include <stdio.h>
#include <math.h>

int main (void)
{
    printIntroduction ();

    double coef_a = NAN, coef_b = NAN, coef_c = NAN;

    while (getCoefficients (&coef_a, &coef_b, &coef_c))
    {
        double x1 = NAN, x2 = NAN;

        int numRoots = solveQuadraticOrLinearEquation (coef_a, coef_b, coef_c, &x1, &x2);

        printNumberOfRootsAndTheirValue (x1, x2, numRoots);

        printf ("press [Enter] to continue");

        skipLine ();

        printf ("\n");
    }
    return 0;
}
