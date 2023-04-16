#pragma once
#include <iostream>
#include <sstream>
#include "View.h"
#include "Soldado.h"

#ifndef PRESENTADOR_H
#define PRESENTADOR_H
class View;

class Presentador {
	View* view;
	Soldado* soldado;

	std::string toUpper(std::string);
	int parseInt(std::string);
public:
	Presentador();
	~Presentador();
	void mostrarMenu();
	void mostrarSubmenu();
	void recogerArma(int);
	void mostrarArma();
	void disparar();
	void soltarArma();
	std::string equiparArma(int);

};
#endif // !PRESENTADOR_H
