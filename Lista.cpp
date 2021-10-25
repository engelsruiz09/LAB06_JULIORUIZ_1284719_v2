#include "Lista.h"
Lista::Lista()
{
	start = nullptr;
	cant = 0;
}

void Lista::Insertar(Pokemon* pokemon)
{
	if (start == nullptr)
	{
		start = new Nodo();
		start->value = pokemon;
		cant++;
	}
	else
	{
		Nodo* nodo = start;

		while (nodo->next != nullptr)
			nodo = nodo->next;

		Nodo* nuevo = new Nodo();
		nuevo->value = pokemon;

		nodo->next = nuevo;
		cant++;
	}
}

Nodo* Lista::ObtenerNodo(int n)
{
	if (!(n >= 0 && n < cant))
		return nullptr;

	Nodo* nodo = start;
	for (int i = 0; i < n; i++)
		nodo = nodo->next;

	return nodo;
}
Pokemon* Lista::ObtenerPokemon(int n)
{
	if (!(n >= 0 && n < cant))
		return nullptr;

	return ObtenerNodo(n)->value;
}

void Lista::Intercambiar(int num1, int num2)
{
	Nodo* nodo1 = ObtenerNodo(num1);
	Nodo* nodo2 = ObtenerNodo(num2);

	std::swap(nodo1->value, nodo2->value);
}

void Lista::Guardar(int pos, Pokemon* pokemon)
{
	Nodo* nodo = ObtenerNodo(pos);
	nodo->value = pokemon;
}

int Lista::Size()
{
	return cant;
}