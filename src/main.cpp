/** @file */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <cmath>

#include "SquareSolve.h"
#include "../TestingSrc/testing.h"
#include "SolverInputOutput.h"
#include "CommandLine.h"
#include "MyFunc.h"

#define SS_INF_ROOT 3

int main(int argc, const char* argv[])
{
    int ProgramMode = FindMode(argc, argv);

    switch (ProgramMode) {
        case USUAL_MODE:
            break;

        case INPUT_TEST_MODE:
            InputReadTest();
            return 0;

        case SS_TEST_MODE:
            SSReadTest();
            return 0;

        case MANUAL_MODE:
            return 0;

        case NO_SWITCHES_ERROR_MODE:
            printf("You should give at least one switch\n"
                   "Print: \"a.exe --help\" to get manual\n");
            return 0;

        case WRONG_SWITCHES_ERROR_MODE:
            printf("You give indefinite switch\n"
                   "Print: \"a.exe --help\" to get manual\n");
            return 0;
    }

    printf("\nSquare equation solver\n\n");
    printf("Enter values of parameters: a, b, c.\n");

    double a = 0, b = 0, c = 0;

    while (!OneKitSolverInput(stdin, &a, &b, &c))
        printf("INPUT ERROR\n"
               "Try again\n");

    double x1 = 0, x2 = 0;
    int NumRoots = SquareSolve(a, b, c, &x1, &x2);

    SolverOutput(NumRoots, x1, x2);

    return 0;
}
