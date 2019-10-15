


#include "ConjuntosDisjuntos.h"
#include "PetrolerosHundidos.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	int C, F;

	std::cin >> F;
	if (!std::cin) {
		return false;
	}
	std::cin >> C;
	std::vector<std::string>petrolero(F);
	std::cin.get();
	for (int i = 0; i < F; i++) {
		std::getline(std::cin, petrolero[i]);
	}
	PetroleroHundido petroleroHundido(petrolero,F,C);
	int hundidos = petroleroHundido.getHundidos();
	std::cout << hundidos << " ";
	
	int actualizaciones;
	std::cin >> actualizaciones;
	for (int i = 0; i < actualizaciones; i++) {
		std::cin >> F >> C;
		petrolero[F - 1][C - 1] = '#';
		petroleroHundido.nuevo(petrolero, F-1, C-1);
		hundidos = petroleroHundido.getHundidos();
		std::cout << hundidos << " ";
	}
	std::cout << "\n";
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("prueba.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}