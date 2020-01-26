#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*
Coste
Nos pide la suma total entre la diferencia del resultado de broncos y sus rivales
los partidos están aleatorios entonces organizamos en un vector ambos y los ordenamos
los de broncos de mayor a menor y de menor a mayor los del rival.
asi la suma es la maxima.
entonces
O(n) = O( 2N + 2NLogN) ==> O(NlogN)
*/
struct myclass {
	bool operator()  (int i, int j) { return (i > j); }
} myope;
bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n != 0) {
		std::vector<int> broncos;
		std::vector<int> rival;
		int points;
		for (int i = 0; i < n; i++) {
			std::cin >> points;
			rival.push_back(points);
		}
		for (int i = 0; i < n; i++) {
			std::cin >> points;
			broncos.push_back(points);
		}
		std::sort(broncos.begin(), broncos.end(), myope);
		std::sort(rival.begin(), rival.end());
		bool victorias = true;
		int i = 0;
		int dif = 0;
		while (victorias && i < n) {
			if (broncos[i] - rival[i] > 0) {
				dif += broncos[i] - rival[i];
			}
			else {
				victorias = false;
			}
			i++;
		}
		std::cout << dif << "\n";
		return true;
	}
	return false;
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