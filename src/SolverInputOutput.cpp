/** @file */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <cmath>

#include "MyFunc.h"

#define SS_INF_ROOT 3

/**
*   @brief take input
*   @brief determines if input is correct
*   @brief correct input include only three double numbers
*
*   @param a [out] a - pointer to the first  coefficient
*   @param b [out] b - pointer to the second coefficient
*   @param c [out] c - pointer to the third  coefficient
*
*   @return (is input correct) ? 1 : 0
*/

int OneKitSolverInput(FILE *stream, double* const a, double* const b, double* const c)
{
    if (fscanf(stream, "%lg %lg %lg", a, b, c) != 3) {

        ClearInputBuff(stream);
        return 0;
    }

    if (IsEmptyInputBuff(stream))
        return 1;

    ClearInputBuff(stream);
    return 0;
}

/**
*   @brief print SSEquation result
*
*   @param NumRoots [in] NumRoots - number of roots
*   @param       x1 [in]       x1 - first root
*   @param       x2 [in]       x2 - second root
*
*   @return nothing
*/

void SolverOutput(const int NumRoots, const double x1, const double x2)
{
    switch(NumRoots) {
        case 0:
            printf("The equation has no roots.\n");
            break;

        case 1:
            printf("The equation has one root.\n"
                   "x = %lg\n", x1);
            break;

        case 2:
            printf("The equation has two roots.\n"
                   "x1 = %lg\n"
                   "x2 = %lg\n", x1, x2);
            break;

        case SS_INF_ROOT:
            printf("The equation has infinity roots.\n");
            break;

        default:
            printf("ERROR in SolverOutput\n"
                   "NumRoots = %d\n", NumRoots);
            break;
    }
}
