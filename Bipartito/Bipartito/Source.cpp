
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "grafo.h"
#include "Bipartito.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void ejercicio(int n, int a) {
	Grafo g(n);
	int v, w;
	for (int i = 0; i < a; i++) {
		std::cin >> v >> w;
		g.ponArista(v, w);
	}
	bipartito Bipartito(g);
	if (Bipartito.esBipartito()) std::cout << "SI\n";
	else std::cout << "NO\n";
	
}
bool resuelveCaso() {
	int v;
	if (std::cin >> v) {
		int a;
		std::cin >> a;
		ejercicio(v, a);
		return true;
	}
	else {
		
		return false;
	}
	
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.in");
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