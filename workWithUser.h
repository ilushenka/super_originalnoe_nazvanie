

/*!
    \brief This function asks the user to run a program test.

    \details It is based on a loop, which if the user types 'Y' (from the word yes),it returns true,

    \details but if the typed character is 'N' (from the word no), it returns false.

    \details If the character typed by the user is different from the above,

    \details this function will use a loop to continuously clear the input buffer by using function buffDelete,

    \details and output the original question until the user enters the correct character.

    @param [in] answerTestQuestion - Writes the first character entered as the user's answer to the testQuestion question.

    \return True if the entered character is 'Y', false if another character has been entered (in this case 'N').

     Below is the code of the function:
    \code
     bool testQuestion ()
     {
        char answerTestQuestion;

        printf ("Start programm test(Y-yes/N-no)?\n");
        scanf  ("%c", &answerTestQuestion);

        while (answerTestQuestion != 'Y' && answerTestQuestion != 'N')
        {
            buffDelete();
            printf ("Enter correct answer.\n");
            printf ("Start programm test(Y-yes/N-no)?\n");
            scanf  ("%c", &answerTestQuestion);
        }
        return (answerTestQuestion == 'Y');
    }
   \endcode
*/
bool  testQuestion     (); // TODO: obsolete

/*!
    \brief   This function presents the program to the user.

    \details This function displays a message to the user, which contains information about the purpose of the program,

    \details the name of the author of the program and the year of its creation.

     Below is the code of the function:
    \code
     void introduction ()
     {
         printf ("Programm for solve square equations (ax^2+bx+c=0)\n");
         printf ("©Илюшечка; 2022.");
         printf ("\n\n\n");
     }
    \endcode
*/
void introduction      ();

/*!
    \brief   This function displays instructions on how to use the program.

    \details This function shows the user what data he needs to enter into the program and how to turn it off.

     Below is the code of the function:
    \code
     void tutorial ()
    {
        printf ("Enter the coefficients value 'a' 'b' 'c'");
        printf ("(to quit, enter q):\n");
    }
    \endcode
*/
void tutorial          (); // TODO: rename
/*!
    \brief   This function clears the input buffer of unnecessary characters.

    \details This function uses a loop and getchar() to clear the input buffer

    \details until it meets the '\n' character (change to a new line).

     Below is the code of the function:
    \code
    void buffDelete ()
    {
        while (getchar () != '\n')
            continue;
    }

    \endcode
*/
void skipLine        ();

/*!
    \brief   This function takes the values of the coefficients 'a', 'b' and 'c' entered by the user.

    \details This function, using the while loop and the scanf function, takes the user-entered values of the coefficients

    \details and terminates the program if the user enters the 'q' character. If the user enters invalid values (different

    \details letters, numbers together with letters), this function clears the buffer with buffDelete() and then asks user

    \details to enter correct data.

    @param [in]  coef_a - The coefficient а of the quadratic equation a*x^2 + b*x + c = 0;
    @param [in]  coef_b - The coefficient b of the quadratic equation a*x^2 + b*x + c = 0;
    @param [in]  coef_c - The coefficient c of the quadratic equation a*x^2 + b*x + c = 0;.

    \return Returns 1 if the first character entered is 'q', 0 if 3 valid variable values were entered.

     Below is the code of the function:
    \code
     int  getCoefficients (double* pcoef_a, double* pcoef_b, double* pcoef_c)
     {
         ASSERT(pcoef_a != NULL);
         ASSERT(pcoef_b != NULL);
         ASSERT(pcoef_c != NULL);

         tutorial ();

         int correct = 0;
         while ((correct = scanf ("%lf %lf %lf", pcoef_a, pcoef_b, pcoef_c)) != 3 || getchar () != '\n')
         {
             if (correct == 0 && getchar () == 'q')
                 return 1;
             else
                 buffDelete ();

             printf ("Error. Enter right coefficients value 'a' 'b' 'c'(to quit, enter q)\n");
         }

         return 0;
     }
    \endcode
*/
bool  getCoefficients   (double *pcoef_a, double *pcoef_b, double *pcoef_c); // TODO: change signature (return type, see .cpp file for details)

/*!
    \brief   Depending on the number of roots, it outputs to the user the number of solutions and their values.

    \details This function, depending on the value of the variable numRoots, displays to the user information

    \details about the number of solutions, as well as the solutions themselves.

    \details If the number of solutions is undefined, this function calls the function undefineNumRoots.

    @param [out] x1 - Shows the value of the first (sometimes the only) root of the equation.
    @param [out] x2 - Shows the value of the second root of the equation.
    @param [in]  numRoots - Variable to which the value of the number of solutions to the equation is passed.


*/
void printNumberOfRootsAndTheirValue       (double x1,       double x2,       int    numRoots); // TODO: rename



