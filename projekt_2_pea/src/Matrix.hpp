#pragma once

#include <memory>
#include <string>

using namespace std;

class Matrix
{
private:
	// Rozmiar macierzy
	int size;

	// Macierz
	int** matrix;

public:
	// Domyślny konstruktor 
	Matrix();

	// Konstruktor macierzy o zadanej wielkości size
	Matrix(const int size_);

	// Destruktor macierzy
	~Matrix();

	// Metoda do wczytywania danych z pliku
	void loadFromFile(const string& fileName_);

	// Metoda do wczytywania danych z pliku XML
	void loadFromXmlFile(const string& fileName_);

	// Metoda generująca losowe dane macierzy
	void generateRandomData(const int size_, const int min, const int max);

	// Przeciążenie operatora []
	int* operator[](int index);

	// Metoda do czyszczenia macierzy
	void clear();

	// Metoda do zwracania wielkości macierzy
	int getSize();

	// Metoda do wyświetlania zawartości macierzy
	void display();
};