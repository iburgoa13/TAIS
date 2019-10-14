#include <iostream>
#include <iomanip>
#include <fstream>
#include "GrafoDirigido.h"
#include "juego.h"
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, K, S, E;
	std::cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0) {
		return false;
	}

	GrafoDirigido tablero(N*N);
	//juego mejorPartida(tablero, 0, K, S, E);
	juego mejorPartida(tablero, 0, K, S, E);
	int min = mejorPartida.minMovimientos(tablero.V() - 1);
	std::cout << min << "\n";
	// escribir sol
	//std::cout << mejorPartida.distancia(tablero.V() - 1) << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while(resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}