#pragma once
#include "Pokemon.h"

class Nodo
{
public:
	Pokemon* value;
	Nodo* next;//un nodo que apunte al siguiente

	Nodo();//constructor
	~Nodo();//destructor
};