#include <stddef.h>

struct Test // (TODO): rename, think of name that reflects what this is testing really
{
    double a;
    double b;
    double c;
    int    expectedNumRoots;
    double expectedX1;
    double expectedX2;
};

void testQuadraticEquastion (); // TODO: rename

bool equationTest           (size_t testNum, const Test *ts); // TODO: rename, it tests equationSolver, not equations themselfs
