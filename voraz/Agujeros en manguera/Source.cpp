#include <iostream>
#include <iomanip>
#include <fstream>


bool resuelveCaso() {
	int N, L;
	if (std::cin >> N) {
		std::cin >> L;
		int agujero;
		int act;
		std::cin >> act;
		agujero = act;
		int parches = 1;
		for (int i = 1; i < N; i++) {
			std::cin >> act;
			if (agujero + L < act) {
				parches++;
				agujero = act;
			}
		}
		std::cout << parches << "\n";
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