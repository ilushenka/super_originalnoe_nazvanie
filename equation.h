#define ASSERT(condition)                                                              \
    if (!(condition))                                                                  \
    {                                                                                  \
        printf ("Ошибка:\n");                                                          \
        printf ("Условие %s не выполняется (недопустимое значение).\n", #condition);   \
        printf ("Расположение ошибки:\n");                                             \
        printf ("\tФайл:              %s \n", __FILE__);                               \
        printf ("\tСтрока:            %d \n", __LINE__);                               \
        printf ("\tФункция:           %s \n", __PRETTY_FUNCTION__);                    \
    }
                                                                                       //переделать
int        solveSquareEquation  (double coef_a,     double coef_b,     double coef_c, double *x1, double *x2);

int        linEquationSolver    (double coef_b,     double coef_c,     double *x1);

static int squareEquationSolver (double coef_a,     double coef_b,     double coef_c, double *x1, double *x2);

bool       isZero               (double numIsZero);

void       ascendingRoots       (double *x1, double *x2);


//! Программа для решения квадратных уравнений.
//!  a*x^2 + b*x + c = 0
//! @param [in]  coef_a - коэффициент а;
//! @param [in]  coef_b - коэффициент b;
//! @param [in]  coef_c - коэффициент c;
//! @param [out] x1     - значение первого корня уравнения;
//! @param [out] x2     - значение второго корня уравнения;
//! @param discr - Дискриминант;
//! @param x1 - первый корень уравнения;
//! @param x2 - второй корень уравнения;
//!
//!
