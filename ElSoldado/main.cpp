#include <iostream>
#include "Presentador.h"

int main() {
	setlocale(LC_ALL, "");
	Presentador* presentador= new Presentador();
	delete presentador;
	return EXIT_SUCCESS;
}
