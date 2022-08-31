#include <stddef.h>

struct StructForTestEquationSolver
{
    double a;
    double b;
    double c;
    int    expectedNumRoots;
    double expectedX1;
    double expectedX2;
};

void testQuadraticEquation  ();

bool equationSolverTest     (size_t testNum, const StructForTestEquationSolver *tests);
