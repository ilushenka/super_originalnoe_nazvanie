#ifndef H_MATH_UTILS
#define H_MATH_UTILS
#define ARRAY_SIZE(mainMassive,massiveInMainMassive)                    \
                   sizeof (massiveInMainMassive) / sizeof (mainMassive)

void swapIfGreater (double *x1, double *x2);

bool isZero    (double numIsZero);

#endif
