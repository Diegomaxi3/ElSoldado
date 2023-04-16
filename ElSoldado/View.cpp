#include <iostream>
#include <sstream>
#include "View.h"
#include "EnumArmas.h"

using namespace std;

View::View(View* _view,Presentador* _presentador) {
	view = _view;
	presentador = _presentador;
	menu = new Menu();
}

void View::gotoxy(int x, int y) {
	HANDLE hand;
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;
	SetConsoleCursorPosition(hand, dwpos);
}

void View::mostrarMenu() {
	system("cls");
	gotoxy(30, 15); cout << menu->getTitulo();
	gotoxy(30, 17); cout << menu->getPregunta();
	gotoxy(30, 18); cout << menu->getLeyenda();

	int posy = 20;
	for (std::string item : menu->getMenuItems()) {
		gotoxy(30, posy);cout << item;
		posy++;
	}
	posy++;
	gotoxy(30, posy); cout << "Opción: ";
}

void View::mostrarSubmenu() {
	system("cls");
	gotoxy(30, 18); cout << menu->getLeyendaSubmenu();

	int posy = 20;
	for (std::string subItem : menu->getSubmenuItems()) {
		gotoxy(30, posy); cout << subItem;
		posy++;
	}
	posy++;
	gotoxy(30, posy); cout << "Opción: ";
}

void View::mostrarDatos(string dato) {
	system("cls");
	gotoxy(30, 20); cout << dato;
	espera();
}

void View::espera() {
	gotoxy(30, 30); cout << "Presiones una tecla para continuar....";
	string espera;
	getline(cin,espera);
}

void View::revisarOpcion(int op) {
	switch (op) {
	case 1: presentador->mostrarSubmenu(); break;
	case 2: presentador->soltarArma(); break;
	case 3: presentador->disparar(); break;
	case 4: presentador->mostrarArma(); break;
	default: mostrarDatos("La opción es incorrecta. ");
	}
}

std::string View::revisarOpcionSubmenu(int op) {
	switch (op) {
	case 1:presentador->recogerArma(REVOLVER); return "x"; break;
	case 2:presentador->recogerArma(RIFLE); return "x"; break;
	case 3:presentador->recogerArma(ESCOPETA); return "x"; break;
	default: mostrarDatos("Opción incorrecta. "); return toString(op); break;
	}
}

View::~View() {
	delete menu;
	presentador = nullptr;
}

std::string View::toString(int num) {
	stringstream aux;
	aux << num;
	return aux.str();
}

