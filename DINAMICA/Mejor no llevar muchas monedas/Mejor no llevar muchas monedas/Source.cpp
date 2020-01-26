#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Matriz.h"
const int INF = 100000000;
typedef struct {
	int valor;
	int cantidad;
	int monedasPuestas;
} tMoneda;


int esPosible(std::vector<tMoneda>  &monedas, const int &N, const int &C) {
	Matriz<int> mapa(N + 1, C + 1, INF);
	for (int i = 0; i <= N; i++) {//es un caso base
		mapa[i][0] = 0;
	}
	for (int i = 1; i <= N; i++) {
		
		for (int j = 1; j <= C; j++) {
			int act = INF;
			int ahora = std::min(monedas[i - 1].cantidad, j / monedas[i - 1].valor);
			for (int x = 0; x <= ahora; x++) {
				act = std::min(act, mapa[i - 1][j - (x*monedas[i - 1].valor)] + x);
				mapa[i][j] = act;
			}
		}
	}

	
	return mapa[N][C];
}
bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)return false;
	std::vector<tMoneda> monedas;
	int i = N;
	int c;
	while (i--) {
		std::cin >> c;
		monedas.push_back({ c,0,0 });
	}
	for (int i = 0; i < monedas.size(); i++) {
		std::cin >> c;
		monedas[i].cantidad = c;
	}
	int C;
	std::cin >> C;
	int x = esPosible(monedas, N, C);
	if (x!=INF) {
		std::cout << "SI " << x << "\n";
	}
	else std::cout << "NO\n";
	return true;
}
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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