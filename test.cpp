#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include "equation.h"
#include "test.h"
#include "math_utils.h"

// TODO: I meant implementing a more generic version of this,
//       something like ARRAY_SIZE for any kind of array type (including tests),
//       it's should be easy if you take a minute to think.
#define MAXTESTNUM sizeof (tests) / sizeof (StructForTestEquationSolver)

static bool areEqualSolutions (const StructForTestEquationSolver *ts, int numRoots, double x1, double x2);

static bool areEqualOrNan  (double diffOne, double diffTwo);

void testQuadraticEquation ()
{
    const struct StructForTestEquationSolver tests[] =
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

    for (size_t testNum = 0; testNum < MAXTESTNUM; testNum++)
        failed += !equationSolverTest (testNum, &tests[testNum]);

    if (failed > 0)
        printf ("Number of failed tests: %d. \n", failed);
    // TODO:                              ^ failed is size_t, but you specified format for int

    printf ("Number of passed tests: %d. \n", MAXTESTNUM - failed);
    // TODO:                          ^ same
    printf ("Total number of tests:  %d.  \n", MAXTESTNUM);
    // TODO:                          ^ same
}

bool equationSolverTest (size_t testNum, const StructForTestEquationSolver *tests)
{
    double x1 = NAN, x2 = NAN;

    int numRoots = checkQuadraticOrLinearEquation (tests->a, tests->b, tests->c, &x1, &x2);

    bool passed = areEqualSolutions(tests, numRoots, x1, x2);

    if (passed)
    {
        printf ("TEST Number %d PASSED.\n", testNum + 1);
        // TODO:              ^ same
    }
    else
    {
        printf ("TEST Number %d FAILED (when a = %lg, b = %lg, c = %lg);\n", testNum + 1,      tests->a,
                                                                             tests->b, tests->c);
        // TODO:              ^ same
        printf ("actual   x1 = %lg, x2 = %lg;\n ", x1, x2);

        if (numRoots == InfRoots)
            printf ("NumRoots = infinity");

        printf ("numRoots = %d; \n", numRoots);
        printf ("Expected x1 = %lg, x2 = %lg ", tests->expectedX1, tests->expectedX2);
        printf ("numRoots = %d. \n", tests->expectedNumRoots);
    }

    return passed;
}

static bool areEqualSolutions (const StructForTestEquationSolver *tests, int numRoots, double x1, double x2)
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
