
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

typedef struct {
	long long int id;
	long long int tiempo;
	long long int periodo;
} tUCM;

bool operator<(tUCM a, tUCM b) {
	return (a.tiempo < b.tiempo) || (a.tiempo == b.tiempo && a.id < b.id);
}
void resuelve(PriorityQueue <tUCM>&cola , const int &k) {
	int i = 0;
	tUCM aux;
	while (i < k) {
		aux = cola.top();
		cola.pop();
		std::cout << aux.id << "\n";
		aux.tiempo += aux.periodo;
		cola.push(aux);
		i++;
	}
}


void ejercicio(const int &n) {
	PriorityQueue<tUCM> cola;
	tUCM casos;
	for (int i = 0; i < n; i++) {
		std::cin >> casos.id >> casos.periodo;
		casos.tiempo = casos.periodo;
		cola.push(casos);
	}
	int turnos;
	std::cin >> turnos;
	resuelve(cola,turnos);
	std::cout << "---\n";
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0)return false;
	else {
		ejercicio(n);
		return true;
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
