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


 /**/
/*struct StructForTest
{
double coef_a[15] =
{0, 0, 0, 0, 0, 1, 1, 1, 1, -1, -1, -1, 5, 1, 0};

double coef_b[15] =
{0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, -1, 6, -5, 2};

double coef_c[15] =
{0, 1, 0, 1, -1, 0, 0, 1, 1, 0, 1, -1, 0, 6, 0};

double expectedX1[15] =
{0, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, -1.2, 2, 0};    //переделать

double expectedX2[15] =
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0};

int numRoots[15] =
{InfRoots, NoRoots, OneRoot, OneRoot, NoRoots, OneRoot, TwoRoots, NoRoots,
 NoRoots, OneRoot, TwoRoots, NoRoots, TwoRoots, TwoRoots, OneRoot};
};*/

void test          ();

int  equationTest  (int testNum, const Test *ts);

bool  areEqualOrNan (double diffOne, double diffTwo);

bool equalSolutions (const Test *ts, int numRoots, double x1, double x2);

