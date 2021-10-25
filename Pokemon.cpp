#include "Pokemon.h"

Pokemon::Pokemon(int numero, string nombre, int generacion, string texto)
{
	this->numero = numero;
	this->nombre = nombre;
	this->generacion = generacion;
	this->texto = texto;
}

int Pokemon::GetNumero()
{
	return numero;
}
string Pokemon::GetNombre()
{
	return nombre;
}
int Pokemon::GetGeneracion()
{
	return generacion;
}

string Pokemon::ToString()
{
	return texto;
}