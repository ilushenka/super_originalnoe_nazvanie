#include <stdio.h>
// TODO: add "include guard" or "#pragma once" in EVERY HEADER FILE to prevent double inclusion
// TODO: rewrite this in English
#define ASSERT(condition)                                                              \
    if (!(condition))                                                                  \
    {                                                                                  \
        printf ("Error:\n");                                                           \
        printf ("The condition %s is not met (invalid value).\n", #condition);         \
        printf ("Расположение ошибки:\n");                                             \
        printf ("\tFile:              %s \n", __FILE__);                               \
        printf ("\tLine:            %d \n", __LINE__);                                 \
        printf ("\tFunction:           %s \n", __PRETTY_FUNCTION__);                   \
    }
// TODO: pay close attention to this function's behaviour when it receives or returns NAN or INF,
//       reflect this behaviour in documentation!
int        checkQuadraticOrLinearEquation  (double coef_a,     double coef_b,     double coef_c, double *x1, double *x2);

int        solveLinearEquation             (double coef_b,     double coef_c,     double *x1);
