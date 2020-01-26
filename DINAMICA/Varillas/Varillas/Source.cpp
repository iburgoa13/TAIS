
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Matriz.h"
typedef struct {
	int longitud;
	int coste;
}tVarillas;
bool esPosible(std::vector<tVarillas> const & varillas,const int &N, const int &L) {
	Matriz<bool> mapa(N + 1, L + 1, false);
	for (int i = 0; i <= N; i++) {
		mapa[i][0] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (varillas[i - 1].longitud > j) {
				mapa[i][j] = mapa[i - 1][j];
			}
			else {
				mapa[i][j] = mapa[i - 1][j] || mapa[i - 1][j - varillas[i - 1].longitud];
			}
		}
	}
	return mapa[N][L];
}
int posibles(std::vector<tVarillas> const & varillas, const int &N, const int &L) {
	Matriz<int> mapa(N + 1, L + 1, 0);
	for (int i = 0; i <= N; i++) {
		mapa[i][0] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (varillas[i - 1].longitud > j) mapa[i][j] = mapa[i - 1][j];
			else mapa[i][j] = mapa[i - 1][j] + mapa[i - 1][j - varillas[i - 1].longitud];
		}
	}
	return mapa[N][L];
}
int minimos(std::vector<tVarillas> const & varillas, const int &N, const int &L) {
	Matriz<int>mapa(N + 1, L + 1, 10000000);
	for (int i = 0; i <= N; i++) {
		mapa[i][0] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (varillas[i - 1].longitud > j)mapa[i][j] = mapa[i - 1][j];
			else mapa[i][j] = std::min(mapa[i - 1][j], mapa[i - 1][j - varillas[i - 1].longitud] + 1);
		}
	}
/*	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (mapa[i][j] > 55) std::cout << "0 ";
			else std::cout << mapa[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";*/
	return mapa[N][L];
}
int minimoCoste(std::vector<tVarillas> const & varillas, const int &N, const int &L) {
	//std::cout << "\n";
	Matriz<int>mapa(N + 1, L + 1, 10000000);
	for (int i = 0; i <= N; i++) {
		mapa[i][0] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (varillas[i - 1].longitud > j)mapa[i][j] = mapa[i - 1][j];
			else mapa[i][j] = std::min(mapa[i - 1][j], mapa[i - 1][j - varillas[i - 1].longitud] + varillas[i-1].coste);
		}
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (mapa[i][j] > 500) std::cout << "00 ";
			else std::cout << mapa[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";*/
	return mapa[N][L];
}
bool resuelveCaso() {
	int N, L;
	std::cin >> N;
	if (!std::cin)return false;

	std::cin >> L;
	int lon, cos;
	std::vector<tVarillas>var;
	int i = N;
	while (i--) {
		std::cin >> lon>> cos;
		var.push_back({ lon,cos });
	}
	if (esPosible(var, N, L)) {
		std::cout<<"SI ";
		std::cout << posibles(var, N, L) << " ";
		std::cout << minimos(var, N, L) << " ";
		std::cout << minimoCoste(var, N, L) << "\n";
	}
	else std::cout << "NO\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}