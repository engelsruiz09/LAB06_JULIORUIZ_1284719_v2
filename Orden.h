#pragma once
#include "Lista.h"
class Orden
{
	void QuickSortProcess(Lista* pkm, int menor, int mayor, string parametro);
	int Divide(Lista* pkm, int menor, int mayor, string parametro);
public:
	void SelectionSort(Lista* pkm, string parametro);
	void QuickSort(Lista* pkm, string parametro);
	void ShellSort(Lista* pkm, string parametro);

};

