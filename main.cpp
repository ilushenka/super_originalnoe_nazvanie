#include "workWithUser.h"
#include "test.h"
#include "equation.h"  //includeguard
#include <stdio.h>
#include <TXLib.h>

int main (void)
{
    introduction ();

    if (testQuestion ())
        test ();
    else
    {
        double coef_a = NAN, coef_b = NAN, coef_c = NAN;
        double x1 = NAN, x2 = NAN;
        while (getCoefficients (&coef_a, &coef_b, &coef_c) != true)
        {
            int numRoots = solveSquareEquation (coef_a, coef_b, coef_c, &x1, &x2);

            varNumRoots (x1, x2, numRoots);

            printf ("press [Enter] to continue");

            buffDelete ();

            printf ("\n");
        }
     }
      return 0;
}



