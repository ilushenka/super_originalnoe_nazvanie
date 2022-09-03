#include "workWithUser.h"
#include "test.h"
#include "equation.h"
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
        // TODO:       ^~~~~ How is this check if it doesn't check, it solves. Call is "solve..."

        printNumberOfRootsAndTheirValue (x1, x2, numRoots);

        printf ("press [Enter] to continue");

        skipLine ();

        printf ("\n");
        }
// TODO:^ inconsistent indentation
    return 0;
}
