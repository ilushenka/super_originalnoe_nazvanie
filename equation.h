// TODO: add "include guard" or "#pragma once" in EVERY HEADER FILE to prevent double inclusion
#define ASSERT(condition)                                                              \
    if (!(condition))                                                                  \
    {                                                                                  \
        printf ("Error:\n");                                                           \
        printf ("The condition %s is not met (invalid value).\n", #condition);         \
        printf ("Error location:\n");                                                  \
        printf ("\tFile:              %s \n", __FILE__);                               \
        printf ("\tLine:            %d \n", __LINE__);                                 \
        printf ("\tFunction:           %s \n", __PRETTY_FUNCTION__);                   \
        abort  ();                                                                     \
    }
int        checkQuadraticOrLinearEquation  (double coef_a,     double coef_b,     double coef_c, double *x1, double *x2);

int        solveLinearEquation             (double coef_b,     double coef_c,     double *x1);
