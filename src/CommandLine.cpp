#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyFunc.h"

#define    NO_SWITCHES_ERROR_MODE 0
#define                USUAL_MODE 1
#define              SS_TEST_MODE 2
#define               MANUAL_MODE 3
#define           INPUT_TEST_MODE 4
#define WRONG_SWITCHES_ERROR_MODE 5

/**
*   @brief display SquareSolver manual
*/

void PrintManual()
{
    printf("\n....................SquareSolver....................\n\n"
           "One of the following switches must be given:\n"
           "        -i    SquareSolve in interactive mode\n"
           "    --help    Display SquareSolver's manual\n"
           "   -t --SS    Testing SquareSolve\n"
           "-t --Input    Testing SolverInput\n\n");
}

/**
*   @brief Determines the mode of SquareSolver
*   @brief There are 4 mode: error, usual, test, manual
*
*   @param argc [in] argc - number of command line arguments
*   @param argv [in] argv -  array of command line arguments
*
*   @return unique number defining the mode
*/

int FindMode(const int argc, const char* const argv[])
{
    if (argc == 1)
        return NO_SWITCHES_ERROR_MODE;

    if (argc == 2) {

        if (!strcmp(argv[1], "-i"))
            return USUAL_MODE;

        if (!strcmp(argv[1], "--help")) {

            PrintManual();

            return MANUAL_MODE;
        }
    }

    if (argc == 3) {
        if (!strcmp(argv[1], "-t") && !strcmp(argv[2], "--SS"))
            return SS_TEST_MODE;

        if (!strcmp(argv[1], "-t") && !strcmp(argv[2], "--Input"))
            return INPUT_TEST_MODE;

    }

    return WRONG_SWITCHES_ERROR_MODE;
}
