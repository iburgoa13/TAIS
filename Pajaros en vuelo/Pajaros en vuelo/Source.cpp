// Iker Burgoa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include <vector>



void resolver(const int &cabeza,const int &num) {

	PriorityQueue<int,std::greater<int>> menores;
	PriorityQueue<int> mayores;

	int cabecilla = cabeza;
	int par1, par2;

	for (int i = 0; i < num; i++) {

		std::cin >> par1 >> par2;
		if (par1 < cabecilla) {
			menores.push(par1);
		}
		else {
			mayores.push(par1);
		}

		
		if (par2 < cabecilla)
		{
			menores.push(par2);
		}
		else {
			mayores.push(par2);
		}


		if (mayores.size() > menores.size()) {
			menores.push(cabecilla);
			cabecilla = mayores.top();
			mayores.pop();
		}
		else if (menores.size() > mayores.size()) {
			mayores.push(cabecilla);
			cabecilla = menores.top();
			menores.pop();
		}


		std::cout << cabecilla << " ";
	}
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	int cabeza,  num;
	std::cin >> cabeza;
	std::cin >> num;
	if (cabeza != 0 && num != 0) {
		resolver(cabeza, num);
		std::cout << "\n";
		return true;
	}
	return false;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
