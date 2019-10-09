// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#include <algorithm>
#include "PriorityQueue.h"

typedef struct {
	int tiempo;
} tDron;

bool operator<(tDron const &a, tDron const &b)  {
	return a.tiempo > b.tiempo;
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void resolver(int drones, int v9, int v15) {
	PriorityQueue<tDron> voltaje9, voltaje15;
	int volt;
	for (int i = 0; i < v9; i++) {
		std::cin >> volt;
		voltaje9.push({ volt });
	}
	for (int i = 0; i < v15; i++) {
		std::cin >> volt;
		voltaje15.push({ volt });
	}

	std::vector<int> pila9, pila15;
	int resultado = 0, max9, max15, diferencia;		
	int i = 0;
	while (!voltaje9.empty() && !voltaje15.empty()) {

		int resultado = 0, max9, max15, diferencia;
		int i = 0;
		while ((!voltaje9.empty() && !voltaje15.empty()) && i < drones) {
			max9 = voltaje9.top().tiempo;
			voltaje9.pop();
			max15 = voltaje15.top().tiempo;
			voltaje15.pop();
			if (max9 > max15) {
				diferencia = max9 - max15;
				pila9.push_back(diferencia);
			}
			else {
				diferencia = max15 - max9;
				pila15.push_back(diferencia);
				}
			resultado = resultado + std::min(max9, max15);
			i++;
		}
		int x = 0;
		while (x != pila9.size()) {
			voltaje9.push({ pila9.at(x) });
			x++;
		}
		pila9.clear();
		//while (!pila9.empty()) pila9.pop_back();
		x = 0;
		while (x != pila15.size()) {
			voltaje15.push({ pila15.at(x) });
			x++;
		}
		pila15.clear();
		//while (!pila15.empty()) pila15.pop_back();
		if(resultado!=0)std::cout << resultado << " ";
	}
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int drones, v9, v15;
	if (std::cin >> drones) {  // fin de la entrada


		std::cin >> v9 >> v15;
		resolver(drones, v9, v15);
		std::cout << "\n";
		return true;
	}
	// escribir sol

	return false;
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