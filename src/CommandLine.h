#ifndef COMMAND_LINE
#define COMMAND_LINE

#define    NO_SWITCHES_ERROR_MODE 0
#define                USUAL_MODE 1
#define              SS_TEST_MODE 2
#define               MANUAL_MODE 3
#define           INPUT_TEST_MODE 4
#define WRONG_SWITCHES_ERROR_MODE 5

int FindMode(const int argc, const char* const argv[]);

#endif
