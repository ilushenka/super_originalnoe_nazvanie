#ifndef H_EQUATION
#define H_EQUATION

/// A set of possible counts of roots
enum numRoots
{
    InfRoots = -1,  ///< Infinite number of solutions;
    NoRoots  =  0,        ///< No solutions;
    OneRoot  =  1,        ///< One solution;
    TwoRoots =  2       ///< Two solutions.
};

int solveQuadraticOrLinearEquation (double coef_a, double coef_b,double coef_c, double *x1, double *x2);

int solveLinearEquation (double coef_b, double coef_c, double *x1);

#endif
