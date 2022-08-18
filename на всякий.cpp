#include <stdio.h>
#include <TXlib.h>
void GETCHARS (void);
void copy (void);
int main (void)
{
    int index;
    char excess_coef[4];
    float discr, x1, x2, coef_a, coef_b, coef_c;

    copy ();

    while (scanf ("%d", &index) != 0)
    {
        if (index == 1)                                                /*есть нулевые коэффициенты*/
        {
            printf ("Введите его(их(слитно)):");
            getchar();
            for (index = 0; excess_coef[index-1] != 10; index++)
            {
                scanf ("%c", &excess_coef[index]);
            }
            index = 0;
            if (excess_coef[index] == 97)                              /*a = 0*/
            {
                if (excess_coef[index+1] == 98)                        /*a = b = 0*/
                {

                    if (excess_coef[index+2] == 99)                    /*a=b=c=0*/
                    {
                        printf ("Да что ты вообще такое???\n0=0 \n");

                        copy ();

                        continue;
                    }

                    printf ("Уравнение не имеет смысла(c=0) \n");

                    copy ();

                    continue;
                }

                if (excess_coef[index+1] == 99)                        /*a = c = 0*/
                {
                    printf ("Уравнение имеет один корень x = 0\n");
                    printf ("(т.к. если в уравнении bx = 0, b != 0 => x = 0) \n");

                    copy ();

                    continue;
                }

                printf ("Введите уравнение формата b*x+c=0: \n");     /*продолжение a = 0*/


                scanf ("%f *x %f", &coef_b, &coef_c);

                printf ("Уравнение имеет один корень, равный %.3f \n", -coef_c/coef_b);

                GETCHARS();

                copy ();

                continue;

            }

            if (excess_coef[index] == 98)                              /*b = 0*/
            {
                if (excess_coef[index+1] == 99)                         /*b = c = 0*/
                {
                    printf ("Уравнение имеет один корень, равный 0 \n");

                    copy ();

                    continue;

                }
                printf ("Введите уравнение формата a*x*x+c = 0: \n"); /*продолжение b = 0*/

                scanf ("%f *x*x %f", &coef_a, &coef_c);

                if (coef_a > 0)
                {
                    if (coef_c < 0)
                    {
                        printf ("Уравнение имеет 2 корня, равные:\n");
                        printf ("x1 = %.3f;", sqrt(-coef_c/coef_a));
                        printf (" x2 = %.3f \n", -sqrt(-coef_c/coef_a));

                        GETCHARS();

                        copy ();

                        continue;

                    }
                    if (coef_c > 0)
                    {
                        printf ("Уравнение не имеет смысла,");
                        printf (" т.к. число в квадрате приравнивается к отрицательному числу: \n");
                        printf ("x^2 = %.3f - не имеет смысла", -coef_c / coef_a);

                        GETCHARS();

                        copy ();

                        continue;

                    }
                }

                if (coef_a < 0)
                {
                    if (coef_c < 0)
                    {
                        printf ("Уравнение не имеет смысла,");
                        printf (" т.к. число в квадрате приравнивается к отрицательному числу: \n");
                        printf ("x^2 = %.3f - не имеет смысла", -coef_c / coef_a);

                        GETCHARS();

                        copy ();

                        continue;

                    }
                    if (coef_c > 0)
                    {
                        printf ("Уравнение имеет 2 корня, равные:\n");
                        printf ("x1 = %.3f;", sqrt(coef_c/-coef_a));
                        printf (" x2 = %.3f", -sqrt(coef_c/-coef_a));

                        GETCHARS();

                        copy ();

                        continue;

                    }
                }
            }
            if (excess_coef[index] == 99)                                  /*с=0*/
            {
                printf ("Введите уравнение формата a*x*x+b*x = 0 \n");

                scanf ("%f *x*x %f", &coef_a, &coef_b);

                discr = coef_b * coef_b;
                x1 = (-coef_b - (sqrt(discr))) / (2 * coef_a);
                x2 = (-coef_b + (sqrt(discr))) / (2 * coef_a);

                printf ("Уравнение имеет два корня, равные:\n");
                printf ("x1 = %5.3f x2 = %5.3f \n", x1, x2);

                GETCHARS();

                copy ();

                continue;

            }
        }
        if (index == 2)                                               /*нет нулевых коэффициентов*/
        {
            printf ("Введите уравнение формата a*x*x+b*x+c = 0: \n");

            scanf ("%f*x*x %f*x %f", &coef_a, &coef_b, &coef_c);
            discr = coef_b * coef_b - 4 * coef_a * coef_c;

            if (discr < 0)                                             /*D<0*/
            {
                printf ("Уравнение не имеет корней");

                GETCHARS();

                copy();

            }                                                          /*D=0*/
            if (discr == 0)
            {
                printf ("Уравнение имеет один корень, равный %.3f \n", -coef_b / (2 * coef_a));

                GETCHARS();

                copy();
            }
            if (discr > 0)                                               /*D>0*/
            {
                x1 = (-coef_b + (sqrt(discr))) / (2 * coef_a);
                x2 = (-coef_b - (sqrt(discr))) / (2 * coef_a);

                printf ("Уравнение имеет два корня: \n");
                printf ("x1 = %5.3f x2= %5.3f \n", x1, x2);

                GETCHARS();

                copy();

            }
        }
    }
    return 0;
}
void copy (void)
{
    printf ("Программа для решения квадратных уравнений \n");
    printf ("Есть ли в Вашем уравнении нулевой коэффициент?");
    printf ("(для завершения введите q)");
    printf ("1-да/2-нет:");
}
void GETCHARS (void)
{
    getchar();
    getchar();
    getchar();
}
