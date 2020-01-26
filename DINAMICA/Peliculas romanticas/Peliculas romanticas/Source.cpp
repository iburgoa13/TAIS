#include <iostream>
#include<fstream>
#include "Matriz.h"
#include <vector>
#include <algorithm>
typedef struct {
	int inicio;
	int duracion;
	int fin;
}tPelis;
bool operator<(tPelis &a, tPelis&b) {
	return a.inicio < b.inicio || (a.inicio==b.inicio && a.duracion>b.duracion);
}
bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)return false;
	std::vector<tPelis> pelis;
	int n = N;
	int hora, min;
	int dur;
	char x;
	int max = 0;
	while (n--) {
		std::cin >> hora >> x >> min >> dur;
		if (max < (hora * 60) + min + dur + 10) max = (hora * 60) + min + dur + 10;
		pelis.push_back({ (hora * 60) + min,dur,(hora * 60) + min + dur + 10 });
	}
	std::sort(pelis.begin(), pelis.end());

	N = pelis.size();
	std::vector<int> duraciones(24 * 60 + 11, 0); 

	for (int i = N; i >= 1; i--) {
		for (int j = 0; j <= 24 * 60; j++) {
			if (pelis[i - 1].inicio >= j && pelis[i - 1].fin <= 24 * 60 + 10) {
				duraciones[j] = std::max(duraciones[j], duraciones[pelis[i - 1].fin] + pelis[i - 1].duracion);
			}
		}
	}

	std::cout << duraciones[0] << "\n";
	return true;
}
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}