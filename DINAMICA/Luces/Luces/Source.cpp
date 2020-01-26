#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Matriz.h"
typedef struct {
	int potencia;
	int coste;
} tBombillas;
/*
caso base mapa[i][0] = 0
          mapa[0][j] = 0

		               si j < bombilla[i-1].potencia ==> mapa[i-1][j]
		  mapa[i][j] = si j >= bombilla[i-1].potencia ==> min( mapa[i-1][j] ,  mapa[i][j - bombilla[i-1].potencia] + coste)
		  O(N*Pmax)
*/
bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)return false;
	int Pmin, Pmax;
	std::cin >> Pmax >> Pmin;
	std::vector<tBombillas>bombillas;
	int i = N;
	int p;
	while (i--) {
		std::cin >> p;
		bombillas.push_back({ p,0 });
	}
	for (int i = 0; i < bombillas.size(); i++) {
		std::cin >> p;
		bombillas[i].coste = p;
	}

	Matriz<int>mapa(N + 1, Pmax + 1, 1000000000);
	for (int i = 0; i <= N; i++) {
		mapa[i][0] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= Pmax; j++) {
			if (j < bombillas[i-1].potencia) {
				mapa[i][j] = mapa[i - 1][j];
				
			}
			else {
				mapa[i][j] = std::min(mapa[i - 1][j], mapa[i][j - bombillas[i - 1].potencia] + bombillas[i - 1].coste);
			}
		}
	}
	int min = mapa[N][Pmin];
	int x = min;
	int potencia = Pmin;
	for (int i = Pmin + 1; i <= Pmax; i++) {
		min = std::min(min, mapa[N][i]);
		if (min != x) {
			potencia = i;
			x = min;
		}
	}
	if (min != 1000000000) {
		std::cout << min << " " << potencia << "\n";
	}
	else std::cout << "IMPOSIBLE\n";
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