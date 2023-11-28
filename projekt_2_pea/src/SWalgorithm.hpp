#pragma once

#include "Matrix.hpp"
#include <memory>
#include <vector>
#include <cmath>

class SWalgorithm
{
public:
	SWalgorithm();
	~SWalgorithm();

	// metoda uruchamiaj�ca algorytm
	int run(const shared_ptr<Matrix>& matrix, int timeLimit, double a);

	// metoda zwracaj�ca minimalny cykl
	std::vector<int> getMinCycle();

	// metoda obliczaj�ca koszt cyklu
	int calculateCost(const shared_ptr<Matrix>& matrix, const std::vector<int>& solution);

	double getTemperature();

	double getProbability();

private:

	// metoda zamieniaj�ca miejscami losowo wybrane wierzcho�ki
	void swap(std::vector<int>& solution);

	// metoda generuj�ca pocz�tkowe rozwi�zanie
	std::vector<int> generateInitialSolution(int n);

private:
	// minimalna waga cyklu
	int minCycleWeight;

	// minimalny cykl
	std::vector<int> minCycle;

	// temperatura (pocz�tkowa)
	double temperature;

	// e^(-1/temperature)
	double probability;

	// temperatura minimalna
	double minTemperature;
};