/** @file */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <cmath>

/**
*   @brief Determines if double number is finite: normal, subnormal or zero, not infinite or NaN
*
*   @param num [in] num - double number
*
*   @return is finite ? 1 : 0
*/

int IsFinite(const double num)
{
    long long int_num = *(long long*)&num;

    long long         infinite_mask = (long long) 0x7ff << 52;
    long long check = infinite_mask & int_num;

    return (check == infinite_mask) ? 0 : 1;
}

/**
*   @brief swap values of two double numbers
*
*   @param a [in] a -  first double number
*   @param b [in] b - second double number
*
*   @return nothing
*/

void swap(double* const a, double* const b)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(a != b);

    double c = *a;
    *a = *b;
    *b = c;
}

/**
*   @brief Compare two double numbers
*
*   @param a [in] a - first number
*   @param b [in] b - second number
*
*   @return (a belong to neighborhood [b - delta; b + delta]) ? 1 : 0
*/

int IsEqual(const double a, const double b)
{
    assert(IsFinite(a));
    assert(IsFinite(b));

    const double delta = 0.00001;

    return fabs(a - b) <= delta;
}

/**
*   @brief Skips all input up to next '\n'
*
*   @param stream [in] stream - input stream
*
*   @return nothing
*/

void ClearInputBuff(FILE* const stream)
{
    assert(stream != NULL);

    char ClearingTemp ='#';
    while ((ClearingTemp = getc(stream)) != '\n' && ClearingTemp != EOF)
        ;
    if (ClearingTemp == '\n')
        ungetc(ClearingTemp, stream);
}

/**
*   @brief Determines is input stream empty
*   @brief empty stream does not include any symbols besides spaces
*
*   @param stream [in] stream - input stream
*
*   @return is empty ? 1 : 0
*/

int IsEmptyInputBuff(FILE* const stream)
 {

    assert(stream != NULL);

    char IsEmptyTemp = ' ';
    while ((IsEmptyTemp = getc(stream)) == ' ' || IsEmptyTemp == '\t')
        ;

    ungetc(IsEmptyTemp, stream);

    if (IsEmptyTemp == '\n' || IsEmptyTemp == EOF)
        return 1;

    return 0;
 }
