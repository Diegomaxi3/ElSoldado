#pragma once
#include <iostream>
#include "IArma.h"
#ifndef REVOLVER_H
#define REVOLVER_H
class Revolver :public IArma {
public:
	Revolver() :IArma("Revolver") {};
	~Revolver() = default;
	std::string disparar() { return "Pum...\n"; };
};
#endif // !REVOLVER_H

