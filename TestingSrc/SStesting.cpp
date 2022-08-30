/** @file */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>

#include "../src/MyFunc.h"
#include "../src/SquareSolve.h"
#include "../src/MyFunc.h"

#define SS_INF_ROOT 3
#define NUM_FILE_INPUT 6

/**
*   @brief Print failed test, values of changed by SquareSolve parameters, expected values of parameters
*
*   @param             a [in]             a - coefficient
*   @param             b [in]             b - coefficient
*   @param             c [in]             c - coefficient
*   @param       NumTest [in]       NumTest - number of test
*   @param RightNumRoots [in] RightNumRoots - right number of roots
*   @param       RightX1 [in]       RightX1 - right first root
*   @param       RightX2 [in]       RightX2 - right second root
*   @param WrongNumRoots [in] WrongNumRoots - wrong number of roots
*   @param       WrongX1 [in]       WrongX1 - wrong first root
*   @param       WrongX2 [in]       WrongX2 - wrong second root
*
*   @return nothing
*/

void SSFailedTestOutput(const double a, const double b, const double c,
                        const int NumTest,
                        const int RightNumRoots, const double RightX1, const double RightX2,
                        const int WrongNumRoots, const double WrongX1, const double WrongX2)
{
    assert(!(RightNumRoots == WrongNumRoots && IsEqual(RightX1, WrongX1) && IsEqual(RightX2, WrongX2)));

    printf("ERROR ON TEST NUMBER %d\n"
           "a = %lg  b = %lg  c = %lg\n"
           "YOUR PARAMETERS: "
           "NumRoots = %d  x1 = %7.5lg  x2 = %7.5lg\n"
           "       EXPECTED: "
           "NumRoots = %d  x1 = %7.5lg  x2 = %7.5lg\n\n",
           NumTest, a, b, c, WrongNumRoots, WrongX1, WrongX2,
                             RightNumRoots, RightX1, RightX2);
}

/**
*   @brief Make useless values of x1 or x2 equal to definite const
*   @brief value of x1 is useless in case of infinite or zero number of roots
*   @brief value of x2 is useless in case of infinite, zero or one number of roots
*
*   @param NumRoots [in] NumRoots - number of equation roots
*   @param       x1 [out]      x1 - first root
*   @param       x2 [out]      x2 - second root
*   @param     x1_0 [in]     x1_0 - definite const for x1
*   @param     x2_0 [in]     x2_0 - definite const for x2
*
*   @return nothing
*/

void ChangeInputSSTest(const int NumRoots, double* const x1,  double* const x2,
                                         const double x1_0, const double x2_0)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    switch(NumRoots) {
        case 0: case SS_INF_ROOT:
            *x1 = x1_0;
            *x2 = x2_0;
            break;

        case 1:
            *x2 = x2_0;
            break;
    }
}

/**
*   @brief Check if roots of square equation (ax^2 + bx + c = 0) right or not
*
*   @param             a [in]             a - coefficient of equation
*   @param             b [in]             b - coefficient of equation
*   @param             c [in]             c - coefficient of equation
*   @param         fails [out]        fails - pointer to the number of failed tests
*   @param       NumTest [in]       NumTest - number of test
*   @param RightNumRoots [in] RightNumRoots - right number of roots
*   @param       RightX1 [in]       RightX1 - right first root
*   @param       RightX2 [in]       RightX2 - right second root
*
*   @return nothing
*
*   @note print test if SquareSolve failed it
*/

void SScheck(const double a, const double b, const double c, int* const fails, const int NumTest,
             const int RightNumRoots, double RightX1, double RightX2)
{
    assert(IsFinite(a));
    assert(IsFinite(b));
    assert(IsFinite(c));
    assert(IsFinite(RightNumRoots));
    assert(IsFinite(RightX1));
    assert(IsFinite(RightX2));

    assert(fails != NULL);

    double      x1_0 = (double) rand(), x2_0 = (double) rand();
    double x1 = x1_0,              x2 = x2_0;

    ChangeInputSSTest(RightNumRoots, &RightX1, &RightX2, x1_0, x2_0);
    int SquareNumRoots = SquareSolve(a, b, c, &x1, &x2);

    int IsRight = (RightNumRoots == SquareNumRoots && IsEqual(RightX1, x1) &&
                                                      IsEqual(RightX2, x2)) ? 1 : 0;
    if (!IsRight) {
        ++*fails;
        SSFailedTestOutput(a, b, c, NumTest, RightNumRoots, RightX1, RightX2,
                                            SquareNumRoots,      x1,      x2);
    } else  {
        printf("Test number %d ok\n\n", NumTest);
    }
}

/**
*   @brief Testing the SquareSolver
*   @brief Read tests from file
*
*   @return nothing
*
*   @note print information about failed tests and total number of failed tests
*/

void SSReadTest()
{
    printf("\n");

    int fails = 0, NumTest = 0, WrongTestFormat = 0, RightNumRoots = 0;
    double a = 0, b = 0, c = 0, RightX1 = 0, RightX2 = 0;

    FILE  *TestsFile = fopen("tests/SStests.txt", "r");
    assert(TestsFile != NULL);

    while (true) {

/*                          double double double             int    double    double              */
/*                               a      b      c   RightNumRoots   RightX1   RightX2              */
        if (fscanf(TestsFile, "%lg    %lg    %lg              %d       %lg       %lg",
                                &a,    &b,    &c, &RightNumRoots, &RightX1, &RightX2) != NUM_FILE_INPUT) {

            if (IsEmptyInputBuff(TestsFile))
                break;

            ++NumTest;
            ++WrongTestFormat;

            ClearInputBuff(TestsFile);
            printf("TEST NUMBER %d WRONG FORMAT\n\n", NumTest);
        } else {

            ++NumTest;
            SScheck(a, b, c, &fails, NumTest, RightNumRoots, RightX1, RightX2);
        }
    }

    fclose(TestsFile);
    printf("SSTesting ended after test number %d\n"
           "              Total failed tests: %d\n"
           "   Total tests with wrong format: %d\n\n", NumTest, fails, WrongTestFormat);
}
