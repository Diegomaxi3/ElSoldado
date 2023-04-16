#pragma once
#include <iostream>
#include "IArma.h"
#ifndef RIFLE_H
#define RIFLE_H
class Rifle :public IArma {
public:
	Rifle() :IArma("Rifle") {};
	~Rifle() = default;
	std::string disparar() { return "Pum Pum Pum!...\n"; };
};
#endif // !RIFLE_H
