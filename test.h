#include <stddef.h>

struct StructForTestEquationSolver
{ //   ^~~~~~ TODO: Do you really need to add word "struct" to struct's name?
  //   It's obvious, and not only that, it's completely irrelevant!
  //   
  //   EquationSolverTest would be a much better name (note most important word comes last "test"),
  //   puts emphasis on what kind of data this holds (note noun as opposed to verbs for functions).

    double a;
    double b;
    double c;
    int    expectedNumRoots;
    double expectedX1;
    double expectedX2;
};

void testQuadraticEquation  ();

bool equationSolverTest     (size_t testNum, const StructForTestEquationSolver *tests);
