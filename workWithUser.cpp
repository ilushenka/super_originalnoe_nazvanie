#include "workWithUser.h"
#include "equation.h"
#include "test.h"
#include <stdio.h>
#include <TXLib.h>
void introduction ()
{
    printf ("Programm for solve square equations (ax^2+bx+c=0)\n");
    printf ("©Илюшечка; 2022.");
    printf ("\n\n\n");
}

int testQuestion ()
{
    char answerTestQuestion;
    printf ("Start programm test(Y-yes/N-no)?\n");
    scanf  ("%c", &answerTestQuestion);

    while (answerTestQuestion != 'Y' && answerTestQuestion != 'N')
    {
        buffDelete();
        printf ("Enter correct answer.\n");
        printf ("Start programm test(Y-yes/N-no)?\n");
        scanf  ("%c", &answerTestQuestion);
    }
    if (answerTestQuestion == 'Y')
        return 1;

    else //if (answerTestQuestion == 'N')
        return 0;
}

void tutorial ()
{
    printf ("Enter the coefficients value 'a' 'b' 'c'");
    printf ("(to quit, enter q):\n");
}

int  getCoefficients (double* pcoef_a, double* pcoef_b, double* pcoef_c)
{
    ASSERT(pcoef_a != NULL);
    ASSERT(pcoef_b != NULL);
    ASSERT(pcoef_c != NULL);

    tutorial ();

    int correct = 0;
    while ((correct = scanf ("%lf %lf %lf", pcoef_a, pcoef_b, pcoef_c)) != 3 || getchar () != '\n')
    {
        if (correct == 0 && getchar () == 'q')
            return 1;
        else
            buffDelete ();

        printf ("Error. Enter right coefficients value 'a' 'b' 'c'(to quit, enter q)\n");
    }

    return 0;
}

void buffDelete ()
{
    while (getchar () != '\n')
        continue;
}

void varNumRoots (double x1, double x2, int numRoots)
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
                undefineNumRoots (numRoots);
        }
}

void undefineNumRoots (int numRoots)
{
    printf ("an indefinite number of solutions\n");
    printf ("The resulting number of roots - %d", numRoots);
}
