#ifndef H_TEST
#define H_TEST
#include <stddef.h>

struct SolveEquationTest
{
    double a;
    double b;
    double c;
    int    expectedNumRoots;
    double expectedX1;
    double expectedX2;
};

void testQuadraticEquation  ();

bool equationSolverTest     (size_t testNum, const SolveEquationTest *tests);

#endif
