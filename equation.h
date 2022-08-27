#define ASSERT(condition)                                                              \
    if (!(condition))                                                                  \
    {                                                                                  \
        printf ("������:\n");                                                          \
        printf ("������� %s �� ����������� (������������ ��������).\n", #condition);   \
        printf ("������������ ������:\n");                                             \
        printf ("\t����:              %s \n", __FILE__);                               \
        printf ("\t������:            %d \n", __LINE__);                               \
        printf ("\t�������:           %s \n", __PRETTY_FUNCTION__);                    \
    }
                                                                                       //����������
int        solveSquareEquation  (double coef_a,     double coef_b,     double coef_c, double *x1, double *x2);

int        linEquationSolver    (double coef_b,     double coef_c,     double *x1);

static int squareEquationSolver (double coef_a,     double coef_b,     double coef_c, double *x1, double *x2);

bool       isZero               (double numIsZero);

void       ascendingRoots       (double *x1, double *x2);


//! ��������� ��� ������� ���������� ���������.
//!  a*x^2 + b*x + c = 0
//! @param [in]  coef_a - ����������� �;
//! @param [in]  coef_b - ����������� b;
//! @param [in]  coef_c - ����������� c;
//! @param [out] x1     - �������� ������� ����� ���������;
//! @param [out] x2     - �������� ������� ����� ���������;
//! @param discr - ������������;
//! @param x1 - ������ ������ ���������;
//! @param x2 - ������ ������ ���������;
//!
//!
