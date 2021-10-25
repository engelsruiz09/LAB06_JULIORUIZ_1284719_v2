#include "Orden.h"
void Orden::SelectionSort(Lista* pkm, string parametro)
{
	for (int i = 0; i < pkm->Size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < pkm->Size(); j++)
		{
			if (parametro == "numero")
			{
				if (pkm->ObtenerPokemon(min)->GetNumero() > pkm->ObtenerPokemon(j)->GetNumero())
					min = j;
			}
			else if (parametro == "nombre")
			{
				if (pkm->ObtenerPokemon(min)->GetNombre() > pkm->ObtenerPokemon(j)->GetNombre() )
					min = j;
			}
			else if (parametro == "generacion")
			{
				if (pkm->ObtenerPokemon(min)->GetGeneracion() > pkm->ObtenerPokemon(j)->GetGeneracion())
					min = j;
			}
		}

		pkm->Intercambiar(i, min);
	}
}

void Orden::QuickSort(Lista* pkm, string parametro)
{
	QuickSortProcess(pkm, 0, pkm->Size() - 1, parametro);
}
void Orden::QuickSortProcess(Lista* pkm, int menor, int mayor, string parametro)
{
	if (menor < mayor)
	{
		int pivot = Divide(pkm, menor, mayor, parametro);
		QuickSortProcess(pkm, menor, pivot - 1, parametro);
		QuickSortProcess(pkm, pivot + 1, mayor, parametro);
	}
}
int Orden::Divide(Lista* pkm, int menor, int mayor, string parametro)
{
	if (parametro == "numero")
	{
		int pivot = pkm->ObtenerPokemon(mayor)->GetNumero();

		int i = menor - 1;

		for (int j = menor; j < mayor; j++)
		{
			if (pkm->ObtenerPokemon(j)->GetNumero() < pivot)
			{
				i++;
				pkm->Intercambiar(i, j);
			}
		}
		pkm->Intercambiar(i + 1, mayor);

		return i + 1;
	}
	else if (parametro == "nombre")
	{
		string pivot = pkm->ObtenerPokemon(mayor)->GetNombre();

		int i = menor - 1;

		for (int j = menor; j < mayor; j++)
		{
			if (pkm->ObtenerPokemon(j)->GetNombre() < pivot)
			{
				i++;
				pkm->Intercambiar(i, j);
			}
		}
		pkm->Intercambiar(i + 1, mayor);

		return i + 1;
	}
	else if (parametro == "generacion")
	{
		int pivot = pkm->ObtenerPokemon(mayor)->GetGeneracion();

		int i = menor - 1;

		for (int j = menor; j < mayor; j++)
		{
			if (pkm->ObtenerPokemon(j)->GetGeneracion() < pivot)
			{
				i++;
				pkm->Intercambiar(i, j);
			}
		}
		pkm->Intercambiar(i + 1, mayor);

		return i + 1;
	}
}


void Orden::ShellSort(Lista* pkm, string parametro)
{
	int n = pkm->Size();
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			if (parametro == "numero")
			{
				Pokemon* temp = pkm->ObtenerPokemon(i);
				int j;
				for (j = i; j >= gap && pkm->ObtenerPokemon(j - gap)->GetNumero() > temp->GetNumero(); j -= gap)
					pkm->Guardar(j, pkm->ObtenerPokemon(j - gap));
				pkm->Guardar(j, temp);
			}
			else if (parametro == "nombre")
			{
				Pokemon* temp = pkm->ObtenerPokemon(i);
				int j;
				for (j = i; j >= gap && pkm->ObtenerPokemon(j - gap)->GetNombre() > temp->GetNombre(); j -= gap)
					pkm->Guardar(j, pkm->ObtenerPokemon(j - gap));
				pkm->Guardar(j, temp);
			}
			else if (parametro == "generacion")
			{
				Pokemon* temp = pkm->ObtenerPokemon(i);
				int j;
				for (j = i; j >= gap && pkm->ObtenerPokemon(j - gap)->GetGeneracion() > temp->GetGeneracion(); j -= gap)
					pkm->Guardar(j, pkm->ObtenerPokemon(j - gap));
				pkm->Guardar(j, temp);
			}
		}
	}
}