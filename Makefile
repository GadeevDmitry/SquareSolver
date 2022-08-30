
all:
	g++ -c src/MyFunc.cpp
	g++ -c src/SquareSolve.cpp
	g++ -c src/main.cpp
	g++ -c src/SolverInputOutput.cpp
	g++ -c src/CommandLine.cpp

	g++ -c TestingSrc/InputTesting.cpp
	g++ -c TestingSrc/SSTesting.cpp

	g++ InputTesting.o MyFunc.o SquareSolve.o SStesting.o main.o SolverInputOutput.o CommandLine.o