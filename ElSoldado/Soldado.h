#pragma once
#include <iostream>
#include "IArma.h"
#ifndef SOLDADO_H
#define SOLDADO_H
class Soldado {
public:
	std::shared_ptr<IArma>arma;
public:
	std::string recogerArma(std::shared_ptr<IArma> arma) { this->arma = arma; return arma->mostrarArma() + " Equiped."; };
	std::string dejarArma() { std::string retorno = arma->mostrarArma() + " Desequiped. "; arma.reset(); return retorno; };
	std::string disparar() {return arma->disparar(); };
	std::string verArma() {return  arma->mostrarArma(); };
	~Soldado() = default;
};
#endif // !SOLDADO_H

