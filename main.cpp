#include "workWithUser.h"
#include "test.h"
#include "equation.h"  // TODO: includeguard COMPLETELY AGREE
#include <stdio.h>
#include <math.h>

int main (void)
{
    introduction ();

    double coef_a = NAN, coef_b = NAN, coef_c = NAN;
    while (getCoefficients (&coef_a, &coef_b, &coef_c))
    {
        double x1 = NAN, x2 = NAN;

        int numRoots = checkQuadraticOrLinearEquation (coef_a, coef_b, coef_c, &x1, &x2);

        printNumberOfRootsAndTheirValue (x1, x2, numRoots);

        printf ("press [Enter] to continue");

        skipLine ();

        printf ("\n");
        }
    return 0;
}
