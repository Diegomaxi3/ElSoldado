#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "Menu.h"
#include "Presentador.h"

#ifndef VIEW_H
#define VIEW_H
class Presentador;

class View {
	View* view;
	Presentador* presentador;
	Menu* menu;

	void espera();
	std::string toString(int);
public:
	View(View* _view, Presentador* _presentador);
	~View();
	void mostrarMenu();
	void mostrarSubmenu();
	void mostrarDatos(std::string);
	void gotoxy(int x, int y);
	void revisarOpcion(int);
	std::string revisarOpcionSubmenu(int);
};
#endif // !VIEW_H
