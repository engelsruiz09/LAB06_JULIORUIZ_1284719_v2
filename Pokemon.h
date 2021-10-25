#pragma once
#include <string>
using namespace std;
class Pokemon
{
public:
	int numero;
	string nombre;
	int generacion;
	
	string texto;
public:
	Pokemon(int numero, string nombre, int generacion, string texto);

	int GetNumero();
	string GetNombre();
	int GetGeneracion();
	string ToString();
};

