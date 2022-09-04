#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include "equation.h"
#include "test.h"
#include "math_utils.h"

static bool areEqualSolutions (const SolveEquationTest *ts, int numRoots, double x1, double x2);

static bool areEqualOrNan  (double diffOne, double diffTwo);

void testQuadraticEquation ()
{
    const struct SolveEquationTest tests[] =
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

    for (size_t testNum = 0; testNum < ARRAY_SIZE(SolveEquationTest, tests); testNum++)
        failed += !equationSolverTest (testNum, &tests[testNum]);

    if (failed > 0)
        printf ("Number of failed tests: %u. \n", failed);
    printf ("Number of passed tests: %u. \n", ARRAY_SIZE(SolveEquationTest, tests) - failed);
    printf ("Total number of tests:  %u. \n", ARRAY_SIZE(SolveEquationTest, tests));
}

bool equationSolverTest (size_t testNum, const SolveEquationTest *tests)
{
    double x1 = NAN, x2 = NAN;

    int numRoots = solveQuadraticOrLinearEquation (tests->a, tests->b, tests->c, &x1, &x2);

    bool passed = areEqualSolutions(tests, numRoots, x1, x2);

    if (passed)
        printf ("TEST Number %u PASSED.\n", testNum + 1);
    else
    {
        printf ("TEST Number %u FAILED (when a = %lg, b = %lg, c = %lg);\n", testNum + 1,      tests->a,
                                                                             tests->b, tests->c);
        printf ("actual   x1 = %lg, x2 = %lg;\n ", x1, x2);

        if (numRoots == InfRoots)
            printf ("NumRoots = infinity");

        printf ("numRoots = %d; \n", numRoots);
        printf ("Expected x1 = %lg, x2 = %lg ", tests->expectedX1, tests->expectedX2);
        printf ("numRoots = %d. \n", tests->expectedNumRoots);
    }

    return passed;
}

static bool areEqualSolutions (const SolveEquationTest *tests, int numRoots, double x1, double x2)
{
    return (numRoots == tests->expectedNumRoots)   &&
           ((areEqualOrNan (tests->expectedX1, x1) && areEqualOrNan(tests->expectedX2, x2)) ||
           (areEqualOrNan (tests->expectedX1, x2)  && areEqualOrNan(tests->expectedX2, x1)));
}

static bool areEqualOrNan (double diffOne, double diffTwo)
{
    if (isnan (diffOne))
        return isnan (diffTwo);

    if (isnan (diffTwo))
        return false;

    return isZero(diffOne - diffTwo);
}
