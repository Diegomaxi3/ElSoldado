#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu() 
{
	this->titulo = "-= = Bienvenido al campo de entrenamiento, Soldado == -";
	this->pregunta = "¿Qué desea hacer?";
	this->leyenda = "(presione el número correspondiente a la opción del menú)";
	this->leyendaSubmenu = "Por favor, escoja el arma que desea utilizar:";
	this->menuItems;
	menuItems.push_back("1 - Recoger Arma");
	menuItems.push_back("2 - Dejar Arma");
	menuItems.push_back("3 - Disparar");
	menuItems.push_back("4 - Mostrar Arma");
	menuItems.push_back("X - Salir");
	this->submenuItems = submenuItems;
	submenuItems.push_back("1 - Revolver");
	submenuItems.push_back("2 - Escopeta");
	submenuItems.push_back("3 - Rifle");
	submenuItems.push_back("X - Salir");
}

string Menu::getTitulo() {
	return titulo;
}

string Menu::getLeyenda() {
	return leyenda;
}

string Menu::getPregunta() {
	return pregunta;
}

string Menu::getLeyendaSubmenu() {
	return leyendaSubmenu;
}

vector<string> Menu::getMenuItems() {
	return menuItems;
}

vector<string> Menu::getSubmenuItems() {
	return submenuItems;
}