#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "Matriz.h"
/*
caso recursivo:
mapa(i)(j) = std:: max(mapa(i-1)(j), mapa(i-1)(j-1),mapa(i-1)(j+1)) + mapa(i)(j)
*/
bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)return false;
	Matriz<int> mapa(N , N , 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> mapa[i][j];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				mapa[i][j] = mapa[i][j] + std::max(mapa[i - 1][j], mapa[i - 1][j + 1]);
			}
			else if (j == N - 1) {
				mapa[i][j] = mapa[i][j] + std::max(mapa[i - 1][j], mapa[i - 1][j - 1]);
			}
			else {
				int aux = std::max(mapa[i - 1][j], mapa[i - 1][j + 1]);
				mapa[i][j] = mapa[i][j] + std::max(aux, mapa[i - 1][j - 1]);
			}
		}
	}
	int max = -1;
	int pos = -1;
	for (int i = 0; i < N; i++) {

		if (max < mapa[N - 1][i]) {
			max = mapa[N - 1][i];
			pos = i+1;
		}
	}
	std::cout << max << " " << pos << "\n";
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