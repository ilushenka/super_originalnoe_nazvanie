#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <stddef.h>
#include "equation.h"
#include "test.h"

void test ()
{
    const struct Test tests[] =
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
    int maxTestNum = sizeof (tests) / sizeof (Test);

    for (int testNum = 0; testNum < maxTestNum; testNum++)
    {
        failed += !(equationTest (testNum, &tests[0]));
    }
    printf ("Number of failed tests: %d", failed);
}

int equationTest (int testNum, const Test *tests)
{
    double x1 = NAN, x2 = NAN;

    int numRoots = solveSquareEquation ((tests[testNum]).a, tests[testNum].b, tests[testNum].c, &x1, &x2);

    if (equalSolutions(&tests[testNum], numRoots, x1, x2))
    {
        printf ("TEST ¹%d SUCCESS.\n", testNum + 1);

        return 1;
    }
    else
    {
        printf ("TEST ¹%d FAILED (when a = %lg, b = %lg, c = %lg);\n", testNum + 1,      tests[testNum].a,
                                                                       tests[testNum].b, tests[testNum].c);

        printf ("actual   x1 = %lg, x2 = %lg ", x1, x2);
        printf ("numRoots = %d; \n", numRoots);

        printf ("Expected x1 = %lg, x2 = %lg ", tests[testNum].expectedX1, tests[testNum].expectedX2);
        printf ("numRoots = %d. \n", tests[testNum].expectedNumRoots);

        return 0;
    }
}

bool equalSolutions (const Test *tests, int numRoots, double x1, double x2)
{
    return (numRoots == tests->expectedNumRoots)   &&
           ((areEqualOrNan (tests->expectedX1, x1) && areEqualOrNan(tests->expectedX2, x2)) ||
           (areEqualOrNan (tests->expectedX1, x2)  && areEqualOrNan(tests->expectedX2, x1)));
}

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
