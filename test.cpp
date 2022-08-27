#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <stddef.h>
#include "equation.h"
#include "test.h"

void test ()
{
    const struct Test ts[] =
    {
//       a   b   c  NumRoots   x1   x2
     {   0,  0,  0, InfRoots,  NAN, NAN  },
     {   0,  0,  1, NoRoots,   NAN, NAN  },
     {   0,  1,  0, OneRoot,   0,   NAN  },
     {   0,  1,  1, OneRoot,  -1,   NAN  },
     {   0,  0, -1, NoRoots,   NAN, NAN  },
     {   1,  0,  0, OneRoot,   0,   NAN  },
     {   1,  1,  0, TwoRoots, -1,   0    },
     {   1,  0,  1, NoRoots,   NAN, NAN  },
     {   1,  1,  1, NoRoots,   NAN, NAN  },
     {  -1,  0,  0, OneRoot,   0,   NAN  },
     {  -1,  0,  1, TwoRoots, -1,   1    },
     {  -1, -1, -1, NoRoots,   NAN, NAN  },
     {   5,  6,  0, TwoRoots, -1.2, 0    },
     {   1, -5,  6, TwoRoots,  2,   3    },
     {   0,  2,  0, OneRoot,   0,   NAN  }
    };
    size_t failed = 0;
    int maxTestNum = sizeof(ts) / sizeof(Test);

    for (int testNum = 0; testNum < maxTestNum; testNum++)
    {
        failed += !(equationTest (testNum, &ts[testNum]));
    }
    printf ("Number of failed tests: %d", failed);
}



int equationTest (int testNum, const Test *ts)
{

    double x1 = NAN, x2 = NAN;

    int numRoots = solveSquareEquation ((ts[testNum]).a, ts[testNum].b, ts[testNum].c, &x1, &x2);

    if (equalSolutions(&ts[testNum], numRoots, x1, x2))
    {
        printf ("TEST №%d SUCCESS.\n", testNum + 1);
        return 1;
    }
    else
    {
        printf ("TEST №%d FAILED (when a = %lg, b = %lg, c = %lg);\n", testNum + 1, ts[testNum].a, ts[testNum].b, ts[testNum].c);

        printf ("actual   x1 = %lg, x2 = %lg ", x1, x2);
        printf ("numRoots = %d; \n", numRoots);

        printf ("Expected x1 = %lg, x2 = %lg ", ts[testNum].expectedX1, ts[testNum].expectedX2);
        printf ("numRoots = %d. \n", ts[testNum].expectedNumRoots);
        return 0;
    }



}


bool equalSolutions (const Test *test, int numRoots, double x1, double x2)
{
    return (numRoots == test->expectedNumRoots) &&
           ((areEqualOrNan (test->expectedX1, x1) && areEqualOrNan(test->expectedX2, x2)) ||
           (areEqualOrNan (test->expectedX1, x2) && areEqualOrNan(test->expectedX2, x1)));
}




    //isnan
                                                                     //переделать ф-цию areequal и сюда вывести случаи

                                                                                        //сделать отдельные ф-ции


bool areEqualOrNan (double diffOne, double diffTwo)
{
    if (isnan (diffOne))
        return isnan (diffTwo);
    else
    if (isnan (diffTwo))
        return false;

    const double border = 1e-8;

    if (fabs (diffOne - diffTwo) < border)
        return true;
    else
        return false;
}


























