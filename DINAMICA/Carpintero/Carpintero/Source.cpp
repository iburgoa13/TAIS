
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"

/*

esfuerzo(i,j) = minimo esfuerzo para cortar un tablon de longitud j, con posibles puntos de corte
del 1 .. i

esfuerzo(i,j) = min(esfuerzo[i][k] + esfuerzo[k][j] + 2 * (cortes[j] - cortes[i])) del intervalo [i+1,j-1]

si i ==j esfuerzo (i,j) = 0
si == j- 1 esfuerzo(i,j) = 0
Coste espacio --> O(N*N)

*/
const int INF = 100000000;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int L, N, corte;
	std::cin >> L >> N;
	if (L == 0 && N == 0)
		return false;

	std::vector<int> cortes;

	//añadimo para que el vector sea 1-Based
	cortes.push_back(0);

	//añadimos origen del tablero
	cortes.push_back(0);

	//añadimos los demas cortes
	for (int i = 1; i <= N; i++) {
		std::cin >> corte;
		cortes.push_back(corte);
	}

	//añadimos el tam del tablero
	cortes.push_back(L);

	int n = cortes.size() - 1;

	Matriz<int> esfuerzo(n + 1, n + 1, 0);


	//como avanzamos en diagonales, calculamos la d, al ser mas lenta se coloca como primer bucle
	for (int d = 1; d <= n - 1; d++) {
		for (int i = 1; i <= n - d; i++) {

			//columna a estudiar
			int j = i + d;

			//variable para hallar minimo
			int esfuerzoActual = INF;

			for (int k = i + 1; k <= j - 1; k++) {
				int temp = esfuerzo[i][k] + esfuerzo[k][j] + 2 * (cortes[j] - cortes[i]);
				if (temp < esfuerzoActual) {
					esfuerzo[i][j] = temp;
					esfuerzoActual = temp;
				}
			}

		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
	
			std::cout << esfuerzo[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << esfuerzo[1][n] << "\n";
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