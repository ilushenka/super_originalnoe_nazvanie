/// A set of possible counts of roots
enum numRoots // TODO: This belongs in equation solver header file.
              // It has nothing to do with math in general and everything to do with equation solving.
{
    InfRoots = -1,  ///< Infinite number of solutions;
    NoRoots  =  0,        ///< No solutions;
    OneRoot  =  1,        ///< One solution;
    TwoRoots =  2       ///< Two solutions.
};

void swapValue (double *x1, double *x2);

bool isZero    (double numIsZero);

