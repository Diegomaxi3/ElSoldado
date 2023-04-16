#include <iostream>
#include "Presentador.h"
#include "Revolver.h"
#include "Rifle.h"
#include "Escopeta.h"
#include "EnumArmas.h"

using namespace std;

Presentador::Presentador() {
	soldado = new Soldado();
	view = new View(view, this);
	mostrarMenu();
}

void Presentador::mostrarMenu() {
	std::string op = "";
	do {
		view->mostrarMenu();
		getline(cin, op);
		if (toUpper(op).compare("X") != 0) view->revisarOpcion(parseInt(op));
	} while (toUpper(op).compare("X") != 0);	
}

void Presentador::mostrarSubmenu() {
	std::string op = "";
	do {
		view->mostrarSubmenu();
		getline(cin, op);
		if (toUpper(op).compare("X") != 0) op = view->revisarOpcionSubmenu(parseInt(op));
	} while (toUpper(op).compare("X") != 0);
}

void Presentador::disparar() {
	if (soldado->arma) { view->mostrarDatos(soldado->disparar()); }
	else { view->mostrarDatos("“Parece que el soldado no tiene ningún arma en sus manos...”"); };
}

void Presentador::mostrarArma() {
	soldado->arma ? view->mostrarDatos(soldado->verArma()):view->mostrarDatos("“Parece que el soldado no tiene ningún arma en sus manos..”");
}

void Presentador::soltarArma() {
	soldado->arma ? view->mostrarDatos(soldado->dejarArma()) : view->mostrarDatos("“Parece que el soldado no tiene ningún arma en sus manos..”");
}

void Presentador::recogerArma(int arma) {
	soldado->arma ? view->mostrarDatos("“Parece que el soldado ya está equipado con otra arma”.") : view->mostrarDatos(equiparArma(arma));
}

std::string Presentador::equiparArma(int arma) {
	switch (arma) {
	case REVOLVER:return soldado->recogerArma(std::make_shared<Revolver>());
	case RIFLE:return soldado->recogerArma(std::make_shared<Escopeta>());
	case ESCOPETA:return soldado->recogerArma(std::make_shared<Rifle>());
	default:return "Por favor ingrese una opcion valida.";
	}
}

std::string Presentador::toUpper(string palabra) {
	string retorno = "";
	for (int i = 0; i < palabra.length(); i++) {
		retorno += toupper(palabra[i]);
	}
	return retorno;
}

int Presentador::parseInt(std::string num) {
	stringstream aux;
	aux << num;
	int retorno;
	aux >> retorno;
	return retorno;
}

Presentador::~Presentador() {
	delete soldado;
	delete view;
}