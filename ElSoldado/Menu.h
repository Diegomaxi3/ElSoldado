#pragma once
#include <iostream>
#include <vector>
#ifndef MENU_H
#define MENU_H
class Menu {
	std::string titulo;
	std::string pregunta;
	std::string leyenda;
	std::string leyendaSubmenu;
	std::vector<std::string> menuItems;
	std::vector<std::string> submenuItems;
public:
	Menu();
	~Menu() = default;
	std::string getTitulo();
	std::string getPregunta();
	std::string getLeyenda();
	std::string getLeyendaSubmenu();
	std::vector<std::string>getMenuItems();
	std::vector<std::string>getSubmenuItems();
};
#endif // !MENU_H
