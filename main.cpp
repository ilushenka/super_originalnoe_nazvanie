#include "workWithUser.h"
#include "test.h"
#include "equation.h"  // TODO: includeguard COMPLETELY AGREE
#include <stdio.h>
#include <math.h>
// TODO: You can use grep to list all TODO in your project, e.g.
//       grep -Hrn 'TODO' *.cpp *.h
//                        ^~~~~ ^~~ expands to all files ending with .h or .cpp in current directory
int main (void)
{
    introduction ();

    // TODO: Move tests out of this file in separate main.cpp (tests do not belong in interactive interface for user)
    if (testQuestion ())
        testQuadraticEquastion ();
    else
    {
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
     }
      return 0;
}
