#include <iostream>
#include <fstream>
#include "GradoValorado.h"
#include "Camiones.h"


bool resuelveCaso() {
	int E, V;
	if (std::cin >> V) {
		std::cin >> E;
		int n, m, valor;
		GrafoValorado<int> grafo(V);
		for (int i = 0; i < E; i++) {
			std::cin >> n >> m >> valor;
			grafo.ponArista({ n - 1,m - 1,valor });
		}
		int casos;
		int ori, dest, peso;
		std::cin >> casos;
		for (int i = 0; i < casos; i++) {
			std::cin >>ori >> dest >> peso;
			Camiones camion(grafo, ori-1, peso);
			if (camion.destino(dest - 1)) {
				std::cout << "SI\n";
			}
			else std::cout << "NO\n";
		}
		return true;
	}
	return false;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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