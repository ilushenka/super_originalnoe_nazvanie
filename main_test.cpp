#include "test.h"
#include "workWithUser.h"
#include <stdio.h>

int main ()
{
    introduction ();

    printf ("This version for testing that programm.\n");
    // TODO:                                      ^ program is spelled with one "m"
    //        And what is the purpose of this message?
    //        Testing "this" program means pretty much nothing.

    testQuadraticEquation ();

    return 0;
}

