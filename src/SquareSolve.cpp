/** @file */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cmath>

#include "MyFunc.h"

#define SS_INF_ROOT 3

/**
*   @brief Solves equation ax + b = 0
*
*   @param a [in]  a - coefficient
*   @param b [in]  b - coefficient
*   @param x [out] x - pointer to the root
*
*   @return number of roots
*
*   @note return SS_INF_ROOT in case of infinite roots
*/

int LineEquationSolve(const double a, const double b, double* const x)
{
    if (IsEqual(a, 0.0)) {

        return IsEqual(b, 0.0) ? SS_INF_ROOT : 0;
    }

    *x = -b / a;

    return 1;
}

/**
*   @brief Solves equation ax^2 + bx + c = 0
*
*   @param  a [in]   a - coefficient
*   @param  b [in]   b - coefficient
*   @param  c [in]   c - coefficient
*   @param x1 [out] x1 - pointer to the  first root
*   @param x2 [out] x2 - pointer to the second root
*
*   @return number of roots
*
*   @note return SS_INF_ROOT in case of infinite roots
*   @note in case if two roots value of x1 always less than value of x2
*/

int SquareSolve(const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert(IsFinite(a));
    assert(IsFinite(b));
    assert(IsFinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    int NumRoot = 0;

    if (IsEqual(a, 0.0)) {

        return LineEquationSolve(b, c, x1);
    }
    else { /* a != 0 */
        double D = b*b - 4*a*c;

        if (IsEqual(D, 0.0)) {
            *x1 = -b / (2 * a);
            NumRoot = 1;
        }
        else if (D > 0) {
            *x1 = (-b - sqrt(D)) / (2 * a);
            *x2 = (-b + sqrt(D)) / (2 * a);

            if ((*x1) > (*x2))
                swap(x1, x2);

            NumRoot = 2;
        } else { /* D < 0 */
            NumRoot = 0;
        }
    }

    return NumRoot;
}
