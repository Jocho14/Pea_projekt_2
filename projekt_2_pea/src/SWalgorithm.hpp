#pragma once

#include "Matrix.hpp"
#include <memory>
#include <vector>
#include <cmath>

class SWalgorithm
{
public:
	// konstruktor
	SWalgorithm();

	// destruktor (domy�lny)
	~SWalgorithm() = default;

	// metoda uruchamiaj�ca algorytm
	int run(const shared_ptr<Matrix>& matrix, int timeLimit, double a);

	// metoda zwracaj�ca minimalny cykl
	std::vector<int> getMinCycle();

	// metoda obliczaj�ca koszt cyklu
	int calculateCost(const shared_ptr<Matrix>& matrix, const std::vector<int>& solution);

	// metoda zwracaj�ca temperature
	double getTemperature();

	// metoda zwracaj�ca prawdopodobie�stwo wed�ug wzoru exp(-delta/Tk)
	double getProbability();

	// metoda zwracaj�ca warto�c minimalnego cyklu
	int getMinCycleWeight();

	// czyszczenie p�l algorytmu
	void clear(); 

	// metoda generuj�ca pocz�tkowe rozwi�zanie przy u�yciu metody zach�annej
	std::vector<int> generateBFSSolution(const shared_ptr<Matrix>& matrix);

private:

	// metoda zamieniaj�ca miejscami losowo wybrane wierzcho�ki
	void swap(std::vector<int>& solution);

	

	// kolejne metody po�wi�cone s� wyliczeniu pocz�tkowej temperatury
	// metoda pomocnicza do obliczenia sumy exp koszt�w
	double expSum(const shared_ptr<Matrix>& matrix, double T, bool isMax);
	
	// metoda do obliecznia chi(T) dla danego T
	double chi(const shared_ptr<Matrix>& matrix, double T);

	// metoda do znalezienia temperatury pocz�tkowej
	double findInitialTemperature(const shared_ptr<Matrix>& matrix, double x0, double epsilon, double p);

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