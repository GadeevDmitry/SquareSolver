#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <cmath>

#include "../src/MyFunc.h"
#include "../src/SolverInputOutput.h"

#define INFINITE_CYCLE 10

/**
*   @brief Count number of attempts to enter right input format
*   @brief Calls OneKitSolverInput for determine if input format is right
*
*   @param stream    [in]     stream - stream with test
*   @param NumCycles [out] NumCycles - pointer to the number of attempts to enter right input format
*
*   @return is input format right ? 1 : 0
*
*   @note in case of infinite attempts return INFINITE_CYCLE
*/

int SolverInputCheck(FILE* const stream, int* const NumCycles)
{
    assert(stream != NULL);
    assert(NumCycles != NULL);

    *NumCycles = 0;
    int SolverInputAns = 0;
    double a = 0, b = 0, c = 0;

    while (!IsEmptyInputBuff(stream) && *NumCycles < INFINITE_CYCLE) {
        ++*NumCycles;
        SolverInputAns = OneKitSolverInput(stream, &a, &b, &c);
    }

    return SolverInputAns;
}

/**
*   @brief Compare right answer and SolverInput answer
*   @brief displays test in case of different answers
*
*   @param   stream [in]   stream - stream with test
*   @param  NumTest [in]  NumTest - number of the test
*   @param RightAns [in] RightAns - right answer on the test
*/

int SolverInputTestsOutput(FILE* const stream, const int NumTest, const int RightAns)
{
    assert(stream != NULL);

    int NumCycles = 0, SolverInputAns = 0;
    SolverInputAns = SolverInputCheck(stream, &NumCycles);

    if (SolverInputAns != RightAns || NumCycles != 1)
        printf("ERROR IN TEST NUMBER %d\n"
               "YOUR ANS: Ans = %3d NumCycles = %3d\n"
               "EXPECTED: Ans = %3d NumCycles =   1\n\n", NumTest, SolverInputAns, NumCycles, RightAns);
    else
        printf("Test number %d ok\n\n", NumTest);
}

/**
*   @brief Read the SolverInput test and displays failed tests
*
*   @return nothing
*/

void InputReadTest()
{
    printf("\n");

    FILE *TestsFile = fopen("tests/InputTests.txt", "r");
    int RightAns = 0, NumTest = 0;

    while (!IsEmptyInputBuff(TestsFile)) {

        ++NumTest;
        fscanf(TestsFile, "%d", &RightAns);

        SolverInputTestsOutput(TestsFile, NumTest, RightAns);

        ClearInputBuff(TestsFile);
        getc(TestsFile);
    }
}
