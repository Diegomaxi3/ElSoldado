#pragma once
#include <iostream>
#include "IArma.h"
#ifndef ESCOPETA_H
#define ESCOPETA_H
class Escopeta :public IArma {
public:
	Escopeta() :IArma("Escopeta ") {};
	~Escopeta() = default;
	std::string disparar() { return "Paaaaa!...\n";  };
};
#endif // !ESCOPETA_H
