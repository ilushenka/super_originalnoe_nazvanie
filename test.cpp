#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include "equation.h"
#include "test.h"
#include "math_utils.h"

static bool equalSolutions (const Test *ts, int numRoots, double x1, double x2);

static bool areEqualOrNan  (double diffOne, double diffTwo);

// TODO: rename so you can tell from the name what it's testing
void testQuadraticEquastion ()
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
    size_t maxTestNum = sizeof (tests) / sizeof (Test);
    // TODO!!!:            ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ consider moving this in macro like ARRAY_SIZE
    //                  note: can be made generic with sizeof(*tests) instead of sizeof(Test),
    //                        think why they do same thing!

    for (size_t testNum = 0; testNum < maxTestNum; testNum++)
        failed += !equationTest (testNum, &tests[0]);

    if (failed > 0)
        printf ("Number of failed tests: %d. \n", failed);

    printf ("Number of passed tests: %d. \n", maxTestNum - failed);
    printf ("Total number of tests:  %d.  \n", maxTestNum);
}

bool equationTest (size_t testNum, const Test *tests)
{
    double x1 = NAN, x2 = NAN;

    int numRoots = checkQuadraticOrLinearEquation (tests[testNum].a, tests[testNum].b, tests[testNum].c, &x1, &x2);
    // TODO!!!:                            ^~~~~~~~~~~~~~    ^~~~~~~~~~~~~~    ^~~~~~~~~~~~~~
    //       Same thing three times! You can make pointer to current test, e.g.
    //       <TestBetterName> *current_test = &tests[testNum];
    //
    //       And access a, b and c with opertor "->", like so: current_test->a, current_test->b, ...

    bool passed = equalSolutions(&tests[testNum], numRoots, x1, x2);

    if (passed)
    {
        printf ("TEST Number %d PASSED.\n", testNum + 1);
    }
    else
    {
        printf ("TEST Number %d FAILED (when a = %lg, b = %lg, c = %lg);\n", testNum + 1,      tests[testNum].a,
                                                                             tests[testNum].b, tests[testNum].c);
                                                                       // TODO: same thing, create pointer to &tests[testNum]
        printf ("actual   x1 = %lg, x2 = %lg;\n ", x1, x2);

        if (numRoots == InfRoots)
            printf ("NumRoots = infinity");

        printf ("numRoots = %d; \n", numRoots);
        printf ("Expected x1 = %lg, x2 = %lg ", tests[testNum].expectedX1, tests[testNum].expectedX2);
        printf ("numRoots = %d. \n", tests[testNum].expectedNumRoots);
                                //   ^~~~~~~~~~~~~~ TODO: create pointer! (same as above)
    }

    return passed;
}

// TODO: Docs are recommended to be in imperative too (this should be Googlable)
//
// Instead of:
// This function checks for xxx...
//
// Use:
// Check for XXX...

// TODO: try to make your function names verbs (areEqualSolutions), and imperative
static bool equalSolutions (const Test *tests, int numRoots, double x1, double x2)
{
    return ( numRoots == tests->expectedNumRoots)  &&
           ((areEqualOrNan (tests->expectedX1, x1) && areEqualOrNan(tests->expectedX2, x2)) ||
           (areEqualOrNan (tests->expectedX1, x2)  && areEqualOrNan(tests->expectedX2, x1)));
}

static bool areEqualOrNan (double diffOne, double diffTwo)
{
    // TODO: read about isfinite and fpclassify
    if (isnan (diffOne))
        return isnan (diffTwo);

    if (isnan (diffTwo))
        return false;

    return isZero(diffOne - diffTwo);
}
