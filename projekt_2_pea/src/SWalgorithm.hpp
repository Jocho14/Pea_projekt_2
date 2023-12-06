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
	int run(const shared_ptr<Matrix>& matrix, const int timeLimit, const double a);

	// metoda generuj�ca pocz�tkowe rozwi�zanie przy u�yciu metody zach�annej
	std::vector<int> generateBFSSolution(const shared_ptr<Matrix>& matrix);

	// metoda obliczaj�ca koszt cyklu
	int calculateCost(const shared_ptr<Matrix>& matrix, const std::vector<int>& solution);

	// czyszczenie p�l algorytmu
	void clear(); 

	// metoda zwracaj�ca minimalny cykl
	std::vector<int> getMinCycle();

	// metoda zwracaj�ca temperature
	double getTemperature();

	// metoda zwracaj�ca prawdopodobie�stwo wed�ug wzoru exp(-delta/Tk)
	double getProbability();

	// metoda zwracaj�ca warto�c minimalnego cyklu
	int getMinCycleWeight();

	// metoda zwracaj�ca moment czasu w kt�rym znaleziono najlepsze rozwi�zanie
	long long getTimeMinCycleFoundAt();

private:
	// metoda przemieszczaj�ca losowy wierzcho�ek w losowe miejsce
	void insert(std::vector<int>& solution);

private:
	// kolejne metody po�wi�cone s� wyliczeniu pocz�tkowej temperatury
	// metoda pomocnicza do obliczenia sumy exp koszt�w
	double expSum(const shared_ptr<Matrix>& matrix, double T, bool isMax);
	
	// metoda do obliecznia chi(T) dla danego T
	double chi(const shared_ptr<Matrix>& matrix, double T);

	// metoda do znalezienia temperatury pocz�tkowej
	double findInitialTemperature(const shared_ptr<Matrix>& matrix, double x0, double epsilon, double p);

private:
	// waga minimalnego cyklu
	int minCycleWeight;

	// minimalny cykl
	std::vector<int> minCycle;

	// moment czasu, w kt�rym odnaleziono najlepsze rozwi�zanie
	long long timeMinCycleFoundAt;

	// temperatura (pocz�tkowa)
	double temperature;

	// temperatura minimalna
	double minTemperature;

	// e^(-1/temperature) prawdopodobie�stwo wyboru gorszego rozwi�zania
	double probability;
}; 