#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*
La idea es rellenar un vector con un numero N de pilas, el cual nos lo pueden dar desordenado
y tenemos que ordenar el vector de menor a mayor, para ir cogiendo la maxima pila y la mas pequeña
O(N + NlogN + N) ==> O(NlogN)
*/
void resuelveCaso() {
	int pilas;
	int volt;
	std::cin >> pilas >> volt;
	int n;
	std::vector<int> voltajePilas;
	for (int i = 0; i < pilas; i++) {
		std::cin >> n;
		voltajePilas.push_back(n);
	}
	std::sort(voltajePilas.begin(), voltajePilas.end());
	int j = pilas - 1;
	int coches = 0;
	int i = 0;
	while(i < pilas && i < j){
		if (voltajePilas[i] + voltajePilas[j] >= volt) {
			j--;
			coches++;
		}
		i++;
	}
	std::cout << coches << "\n";
}
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}