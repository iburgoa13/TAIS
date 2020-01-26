#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "Matriz.h"

/*
	aibofobia(i,j) = mínimo número de letras i a añadir para alcanzar la palabra j y esta sea un palindromo.

 Caso base:
	aibofobia(i,j) = 0 si i == j.

 Caso recursivo:
	aibofobia(i,j) = aibofobia(i+1,j-1) si pal[i] == pal[j]
	aibofobia(i,j) = min(aibofobia(i+1,j), aibofobia(i,j-1) +  si pal[i] != pal[j]


 COSTE:
	O(n*n) en tiempo y espacio, siendo n el numero de letras de la palabra.

 */

bool resuelveCaso() {

	std::string word;
	std::cin >> word;

	if (!std::cin) return false;

	int N = word.size();

	Matriz<int> aibofobia(N + 1, N + 1, 0);

	for (int d = 1; d <= N - 1; ++d) {
		for (int i = 1; i <= N - d; ++i) {
			int j = i + d;
			if (word[i - 1] == word[j - 1])
				aibofobia[i][j] = aibofobia[i + 1][j - 1];
			else
				aibofobia[i][j] = std::min(aibofobia[i + 1][j], aibofobia[i][j - 1]) + 1;
		}
	}

	std::cout << aibofobia[1][N] << "\n";

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