
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <climits>
#include "bintree.h"
using namespace std;
const int EMPTY = -1;

typedef struct {
	bool equilibrio = true;
	bool busqueda = true;
	int altura = 0;
	int minimo;
	int maximo;
} tSol;

tSol ejercicio(bintree<int> const& tree) {
	tSol sol, der, izq;
	//caso vacio
	if (tree.empty()) {
		sol.equilibrio = true;
		sol.busqueda = true;
	}
	//caso en el que soy hoja
	else if (tree.left().empty() && tree.right().empty()) {
		sol.busqueda = true;
		sol.equilibrio = true;
		sol.maximo = tree.root();
		sol.minimo = tree.root();
		sol.altura = 1;
	}
	else if (tree.left().empty()) {
		izq = ejercicio(tree.left());
		der = ejercicio(tree.right());
		sol.altura = 1 + der.altura;

		sol.maximo = std::max(tree.root(), der.maximo);
		sol.minimo = std::min(tree.root(), der.minimo);

		sol.equilibrio = der.equilibrio && izq.equilibrio && (abs(der.altura - izq.altura) <= 1);
		sol.busqueda = der.busqueda && izq.busqueda && der.minimo > tree.root();
	}
	else if (tree.right().empty()) {
		izq = ejercicio(tree.left());
		der = ejercicio(tree.right());
		sol.altura = 1 + izq.altura;

		sol.maximo = std::max(tree.root(), izq.maximo);
		sol.minimo = std::min(tree.root(), izq.minimo);

		sol.equilibrio = der.equilibrio && izq.equilibrio && (abs(der.altura - izq.altura) <= 1);
		sol.busqueda = der.busqueda && izq.busqueda && izq.maximo < tree.root();
	}
	else {
		izq = ejercicio(tree.left());
		der = ejercicio(tree.right());
		sol.altura = 1 + std::max(der.altura, izq.altura);

		int minimoTotal = std::min(izq.minimo, der.minimo);
		int maximoTotal = std::max(izq.maximo, der.maximo);

		sol.minimo = std::min(minimoTotal, tree.root());
		sol.maximo = std::max(maximoTotal, tree.root());
		sol.busqueda = izq.maximo < tree.root() && der.minimo > tree.root() && izq.busqueda && der.busqueda;
		sol.equilibrio = izq.equilibrio && der.equilibrio && (abs(izq.altura - der.altura) <= 1);

	}
	return sol;
}
void resuelveCaso() {
	bintree<int> arbol;
	arbol = leerArbol(EMPTY);

	int alt = 0;
	tSol sol = ejercicio(arbol);
	if (sol.busqueda && sol.equilibrio) std::cout << "SI" << endl;
	else std::cout << "NO" << endl;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}