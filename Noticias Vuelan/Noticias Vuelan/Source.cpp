
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void ejercicio(const int &N, const int &M) {
	ConjuntosDisjuntos particion(N);
	for (int i = 0; i < M; i++) {
		int capacidad;
		std::cin >> capacidad;
		int prim, other;
		if (capacidad > 0) {
			std::cin >> prim;
			prim = prim - 1;
			for (int x = 1; x < capacidad; x++) {
				std::cin >> other;
				other = other - 1;
				particion.unir(prim, other);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		std::cout << particion.tam(i) << " ";
	}
	std::cout << "\n";

	//std::vector<int> total = noticias.totalNoticias();
	//print(total);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	int N;
	if (std::cin >> N) {
		int M;
		std::cin >> M;
		ejercicio(N, M);
		return true;
	}
	else {

		return false;
	}

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