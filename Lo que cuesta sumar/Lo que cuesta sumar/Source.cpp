
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"



long long int ejercicio(PriorityQueue<long long int> suma) {
	long long int sum1, sum2, e = 0;

	while (suma.size() > 1) {
		sum1 = suma.top();
		suma.pop();
		sum2 = suma.top();
		suma.pop();
		e += sum1 + sum2;
		suma.push(sum1+sum2);
	}
	return e;
}
bool resuelveCaso() {
	int n;
	long long num;
	std::cin >> n;
	if (n == 0) return false;
	else {
		PriorityQueue<long long int> suma;
		for (int i = 0; i < n; i++) {
			std::cin >> num;
			suma.push(num);
		}
		std::cout << ejercicio(suma) << "\n";
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
