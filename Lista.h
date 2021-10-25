#pragma once
#include "Nodo.h"
class Lista
{
public:
	Lista();
	Nodo* start;
	int cant;//num de elementos
public:
	void Insertar(Pokemon* pokemon);

	Nodo* ObtenerNodo(int pos);
	Pokemon* ObtenerPokemon(int pos);

	void Intercambiar(int num1, int num2);

	void Guardar(int pos, Pokemon* pokemon);

	int Size();
};