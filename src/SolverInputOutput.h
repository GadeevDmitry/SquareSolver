#ifndef SOLVER_INPUT_OUTPUT
#define SOLVER_INPUT_OUTPUT

int OneKitSolverInput(FILE *stream, double* const a, double* const b, double* const c);
void SolverOutput(const int NumRoots, const double x1, const double x2);

#endif
