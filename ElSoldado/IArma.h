#pragma once
#include <iostream>
#ifndef ARMA_H
#define ARMA_H
class IArma {
	std::string nombre;
public:
	IArma(std::string nombre) :nombre(nombre) {};
    virtual ~IArma() {};
	virtual std::string disparar() = 0;
	std::string mostrarArma() { return nombre; };
};
#endif // !ARMA_H
