#include "workWithUser.h"
#include "equation.h"
#include "math_utils.h"
#include <stdio.h>
#include <assert.h>

bool testQuestion () // TODO: considering other changes, will become obsolete
{
    char answerTestQuestion = 0;
    printf ("Start programm test(Y-yes/N-no)?\n");
    scanf  ("%c", &answerTestQuestion);

    while (answerTestQuestion != 'Y' && answerTestQuestion != 'N')
    {
        skipLine();
        printf ("Enter correct answer.\n");
        printf ("Start programm test(Y-yes/N-no)?\n");
        scanf  ("%c", &answerTestQuestion);
    }
    return (answerTestQuestion == 'Y');

}

void introduction ()
{
    printf ("Programm for solve square equations (ax^2+bx+c=0)\n");
    printf ("©Ilushechka; 2022."); // TODO: more legally accepted style would be: "Copyright (c) <First Name> <Second Name> <Year>
    printf ("\n\n\n");
}

void tutorial () // TODO: looks like prompt, not like tutorial to me. Improve (add tutorial or rename)
{
    printf ("Enter the coefficients value 'a' 'b' 'c'");
    printf ("(to quit, enter q):\n");
}

void skipLine () // TODO: rename, definitely not buffDelete (and not bufferDelete either)
{                  //       e.g. skip_line
    while (getchar () != '\n') // TODO: What if getchar() returns EOF? Check!
        continue;
}

// TODO: this function actually returns bool, reflect that in return type
//       if you wanted it to return error code, you should have written
//       enum ErrorCode { SUCCESS = 0, ... }; to reflect that, and change
//       function signature appropriately:
//
//       ErrorCode getCoefficients(double* a, double* b, double* c);
//
//       And then never compare ErrorCode with bool (like true and false),
//       and also never use boolean operators with it, e.g.
//       !getCoefficients(...) in described case would be confusing as hell
bool getCoefficients (double* pcoef_a, double* pcoef_b, double* pcoef_c)
{
    ASSERT(pcoef_a != NULL);
    ASSERT(pcoef_b != NULL);
    ASSERT(pcoef_c != NULL);

    tutorial ();
    // TODO: many style guides advise using space before bracket in control flow constructs, e.g.
    //
    //       while (...)
    //            ^ note space
    //
    //       while function declarations and calls are overwhelmingly written without this space:
    //
    //       scanf(" ... ", ...);
    //            ^ note no space here
    //
    //       void my_function(...);
    //                       ^ and no space here
    //
    // Since it's very common and useful convention I would advise you to look into using it.

    int correct = 0;
    while ((correct = scanf ("%lf %lf %lf", pcoef_a, pcoef_b, pcoef_c)) != 3 || getchar () != '\n')
    {                                                                    //^ - if user type 3 numbers for coefficients
      // (TODO): consider adding comment ^ to all floating literals except 0, 1 and -1
        if (correct == 0 && getchar () == 'q')
            return false; // TODO: Why getCoefficients returns true when it fails, unintuitive as hell
        else
            skipLine ();

        printf ("Error. Enter right coefficients value 'a' 'b' 'c' (to quit enter q)\n");
    }

    return true; // TODO: if you decide to use error codes, you should return enum values instead, e.g. SUCCESS
              //       on the other hand, if you settle on using bool as return type, use explicit true and false instead of 1 and 0
}


// TODO: definitely not varNumRoots, describeSolution, worst case scenario printRoots, but for God's sake not varNumRoots
void printNumberOfRootsAndTheirValue (double x1, double x2, int numRoots)
{
    switch (numRoots)
        {
            case InfRoots:
                printf ("Equation has an infinite number of solutions. \n");
                break;

            case NoRoots:
                printf ("Equation has no solutions. \n");
                break;

            case OneRoot:
                printf ("Equation has one solution x = %lf. \n", x1);
                break;

            case TwoRoots:
                printf ("Equation has 2 solutions: \n");
                printf ("x1 = %lf; x2 = %lf. \n", x1, x2);
                break;

            default:
                assert(false && "ERROR! WRONG NUMBER OF ROOTS!");

                // (TODO): consider adding assert(false);
                //       preferably with comment!
                //
                // There's a common pattern that let's
                // you add "comment" to assert, looks like this:
                //
                // assert(condition && "Comment why failed");
                //
                // For example, here a good comment would be:
                // assert(false && "Unreachable! Illegal number of roots.");
                //
                // Some big projects have functions with analogical behavior,
                // e.g. llvm_unreachable("Comment"); in LLVM codebase
        }
}

// (TODO): after changes described above (when this function is call), it will become obsolete
