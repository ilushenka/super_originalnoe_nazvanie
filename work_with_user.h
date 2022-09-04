#ifndef H_WORK_WITH_USER
#define H_WORK_WITH_USER
/*!
    \brief Present the program to the user.

           Display a message to the user, which contains information about the purpose of the program,

           the name of the author of the program and the year of its creation.
*/
void printIntroduction ();

/*!
    \brief Display instructions on how to use the program.

           Show the user what data he needs to enter into the program and how to turn it off.
*/
void printInputDescription ();

/*!
    \brief Clear the input buffer of unnecessary characters.

           Uses a loop and getchar() to clear the input buffer

           until it meets the '\n' character (change to a new line).
*/
void skipLine ();

/*!
    \brief Take the values of the coefficients 'a', 'b' and 'c' entered by the user.

           Using the while loop and the scanf function, take the user-entered values of the coefficients

           and terminates the program if the user enters the 'q' character. If the user enters invalid values (different

           letters, numbers together with letters), this function clears the buffer with buffDelete() and then asks user

           to enter correct data.

    @param [in]  coef_a - The coefficient à of the quadratic equation a*x^2 + b*x + c = 0;
    @param [in]  coef_b - The coefficient b of the quadratic equation a*x^2 + b*x + c = 0;
    @param [in]  coef_c - The coefficient c of the quadratic equation a*x^2 + b*x + c = 0;.

    \return Returns 1 if the first character entered is 'q', 0 if 3 valid variable values were entered.
*/
bool getCoefficients (double *pcoef_a, double *pcoef_b, double *pcoef_c);

/*!
    \brief Depending on the number of roots, it outputs to the user the number of solutions and their values.

           Depending on the value of the variable numRoots, displays to the user information

           about the number of solutions, as well as the solutions themselves.

           If the number of solutions is undefined, this function calls the function undefineNumRoots.

    @param [out] x1 - Shows the value of the first (sometimes the only) root of the equation.
    @param [out] x2 - Shows the value of the second root of the equation.
    @param [in]  numRoots - Variable to which the value of the number of solutions to the equation is passed.
*/
void printNumberOfRootsAndTheirValue (double x1, double x2, int numRoots);

#endif


