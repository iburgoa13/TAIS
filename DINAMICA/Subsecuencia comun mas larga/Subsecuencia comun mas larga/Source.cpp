#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

#include "Matriz.h"


/*
Casos base:
Palabra X e Y
 mapa(i,0) = 0 donde palabra Y esta vacia
 mapa(0,j) = 0 donde palabra X esta vacia

 recursion
 mapa(i,j) = mapa(i-1)(j-1)+ 1  si x(i-1) = y(j-1)
 mapa(i,j) = max ( mapa(i-1)(j), mapa(i)(j-1)) si  x(i-1) != y(j-1)
*/
bool resuelveCaso() {
	std::string X, Y;
	std::cin >> X;
	if (!std::cin)return false;

	std::cin >> Y;
	int N, M;
	N = X.length();
	M = Y.length();
	Matriz<int> mapa(N + 1, M + 1, 1000000000);
	for (int i = 0; i <= N; i++) {
		mapa[i][0] = 0;
	}
	for (int j = 0; j <= M; j++) {
		mapa[0][j] = 0;
	}

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= M; j++) {
			if (X[i - 1] == Y[j - 1]) {
				mapa[i][j] = mapa[i - 1][j-1] + 1;
			}
			else {
				mapa[i][j] = std::max(mapa[i - 1][j], mapa[i][j - 1]);
			}
		}
	}

	int pY = M;
	int pX = N;
	int count = 0;
	std::string palabra(mapa[N][M], ' ');
	while (count < mapa[N][M]) {
		if (X[pX - 1] == Y[pY - 1]) {
			palabra[mapa[N][M] - count - 1] = X[pX - 1];
			pX--;
			pY--;
			count++;
		}
		else {
			if (mapa[pX][pY] == mapa[pX - 1][pY]) {
				pX--;
			}
			else if (mapa[pX][pY] == mapa[pX][pY - 1]) {
				pY--;
			}
		}
	}

	for (int i = 0; i < palabra.size(); i++) {
		std::cout << palabra[i];
	}
	std::cout << "\n";
	return true;
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