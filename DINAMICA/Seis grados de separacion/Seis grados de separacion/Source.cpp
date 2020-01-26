#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include<unordered_map>
#include"Matriz.h"
/*
Funciones recursivas-->
Matriz de adyacencia

			|0 si i = j
	G[i][j] |coste si hay arista de i a j
			|INF si no hay arista de i a j

Se aplica algoritmo de Floyd
Timepo-->O(n^3)
Espacio --> Co +tamHashMap en espacio adicional
*/
/*
              ==> 0 si i = j
grafo[i][j] = ==> coste si hay arista de i a j
              ==> 1000000 si no hay arista de i a j

			  Es algoritmo de Floyd ==> Tiempo ==> O(n^3) y espacio ==> Co + tamaño del mapa
*/ 
void Floyd(Matriz<int> &grafo, Matriz<int> &C, Matriz<int> &camino) {
	int n = grafo.numfils() - 1;
	C = grafo;
	camino = Matriz<int>(n + 1, n+1, 0);
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int temp = C[i][k] + C[k][j];
				if (temp < C[i][j]) {
					C[i][j] = temp;
					camino[i][j] = k;
				}
			}
		}
	}
}
bool resuelveCaso() {
	int P, R;
	std::cin >> P;
	if (!std::cin)return false;
	std::cin >> R;
	//por que es el minimo
	Matriz<int> relaciones(P + 1, P + 1, 100000000);
	for (int i = 1; i <= P; ++i) {
		relaciones[i][i] = 0;
	}
	std::unordered_map<std::string, int> conexion;
	int cont = 1;
	std::string a, b;
	std::cin.get();
	for (int i = 0; i < R; i++) {
		std::cin >> a >> b;
		if (conexion[a] == 0) {
			conexion[a] = cont;
			cont++;
		}
		if (conexion[b] == 0) {
			conexion[b] = cont;
			cont++;
		}
		//insertamos su relacion en diagonales
		relaciones[conexion[a]][conexion[b]] = 1;
		relaciones[conexion[b]][conexion[a]] = 1;
	}
	Matriz<int> C(0, 0); Matriz<int> camino(0, 0);
	Floyd(relaciones, C, camino);
	int max = 0;
	for (int i = 1; i <= P; i++) {
		for (int j = 1; j <= P; j++) {
			max = std::max(max, C[i][j]);
		}
	}
	if (max == 100000000)std::cout << "DESCONECTADA\n";
	else std::cout << max << "\n";
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