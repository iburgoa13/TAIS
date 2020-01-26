#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include "PriorityQueue.h"

typedef struct {
	int ini;
	int fin;
} tActividad;
struct myclass {
	bool operator() (tActividad const &i, tActividad const &j) {
		return i.ini < j.ini;// || (i.ini == j.ini && i.fin < j.fin);
	}
}myope;
bool operator <(const tActividad & a, const tActividad &b) {
	return a.ini < b.ini;
}
bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0)return false;
	std::vector<tActividad> actividad;
	int ini, fin;
	for (int i = 0; i < n; i++) {
		std::cin >> ini >> fin;
		actividad.push_back({ ini,fin });
	}
	std::sort(actividad.begin(), actividad.end(), myope);
	int compi = 0;
	//PriorityQueue<int,std::greater<int>> amigos;
	std::priority_queue<int, std::vector<int>,
		std::greater<int>> amigos;
	

	amigos.push(actividad[0].fin);
	for (int i = 1; i < actividad.size(); i++) {
		//si puede encargarse alguien se lo aginamos
		if (actividad[i].ini >= amigos.top()) {
			amigos.pop();
			amigos.push(actividad[i].fin);
		}

		else if (amigos.top() >= actividad[i].ini) {
			//sino quedan amigos necesitamos uno
			if (amigos.empty()) {
				compi++;
				amigos.push(actividad[i].fin);
			}
			// si hay un amigo que esta libre lo asignamos
			else if (amigos.top() <= actividad[i].ini) {
				amigos.pop();
				amigos.push(actividad[i].fin);
			}
			//si hay amigos pero no estan libres necesitamos otro
			else {
				compi++;
				amigos.push(actividad[i].fin);
			}
		}
	}
	std::cout << compi << "\n";
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