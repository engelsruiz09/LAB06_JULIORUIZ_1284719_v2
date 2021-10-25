#pragma once
#include <string>
class Pokemons
{
public:
	int nationalNumber;
	int genNumber;
	char nombre[30] = { "" };
	int tamNombre;
	Pokemons* siguientePokemon;
	Pokemons* anteriorPokemon;
public:
	Pokemons();

};

