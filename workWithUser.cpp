#include "workWithUser.h"
#include "equation.h"
#include "math_utils.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void introduction ()
{
    printf ("Programm for solve square equations (ax^2+bx+c=0)\n");
    printf ("(c) Ilya Pramskiy; 2022.");
    printf ("\n\n\n");
}

void explainInput ()
{
    printf ("Enter the coefficients value 'a' 'b' 'c'");
    printf ("(to quit, enter q):\n");
}

void skipLine ()
{
    int skip; // TODO: why isn't type "char"? And initialize it, please.

    do
    {
        skip = getchar ();
        continue;
    }
    while (skip != '\n' && skip != EOF);
}

bool getCoefficients (double* pcoef_a, double* pcoef_b, double* pcoef_c)
{
    ASSERT(pcoef_a != NULL);
    ASSERT(pcoef_b != NULL);
    ASSERT(pcoef_c != NULL);

    explainInput ();

    int correct = 0;
    while ((correct = scanf ("%lf %lf %lf", pcoef_a, pcoef_b, pcoef_c)) != 3 || getchar () != '\n')
    {                                                                    //^ - if user type 3 numbers for coefficients
        //                                                               TODO:            ^ inconsistent tense
        if (correct == 0 && getchar () == 'q')
            return false;
        else
            skipLine ();

        printf ("Error. Enter right coefficients value 'a' 'b' 'c' (to quit enter q)\n");
    }

    return true;
}

void printNumberOfRootsAndTheirValue (double x1, double x2, int numRoots)
{
    switch (numRoots)
        {
            case InfRoots:
                printf ("Equation has an infinite number of solutions. \n");
                break;

            case NoRoots:
                printf ("Equation has no solutions. \n");
                break;

            case OneRoot:
                printf ("Equation has one solution x = %lf. \n", x1);
                break;

            case TwoRoots:
                printf ("Equation has 2 solutions: \n");
                printf ("x1 = %lf; x2 = %lf. \n", x1, x2);
                break;

            default:
                assert(false && "ERROR! WRONG NUMBER OF ROOTS!");
        }
}
