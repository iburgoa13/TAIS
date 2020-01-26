#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
typedef struct {
	int ini;
	int fin;
} tConstruccion;
struct myclass {
	bool operator()  (tConstruccion i, tConstruccion j)
	{
		return i.fin < j.fin || (i.fin == j.fin && i.ini < j.ini);
	}
} myope;

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n != 0) {
		std::vector<tConstruccion> v;
		int i, f;
		for (int x = 0; x < n; x++) {
			std::cin >> i >> f;
			v.push_back({ i,f });
		}
		std::sort(v.begin(), v.end(), myope);
		int edi = 1;
		auto min = v.at(0).fin;
		for (int i = 1; i < v.size(); i++) {
			if (v.at(i).ini >= min) {
				edi++;
				min = v.at(i).fin;
			}
		}
		std::cout << edi << "\n";
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