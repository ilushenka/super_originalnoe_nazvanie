enum numRootsForTest
{
InfRoots = -1,
NoRoots,
OneRoot,
TwoRoots
};

struct Test
{
double a;
double b;
double c;
int    expectedNumRoots;
double expectedX1;
double expectedX2;
};

void test           ();

int  equationTest   (int testNum, const Test *ts);

bool areEqualOrNan  (double diffOne, double diffTwo);

bool equalSolutions (const Test *ts, int numRoots, double x1, double x2);

