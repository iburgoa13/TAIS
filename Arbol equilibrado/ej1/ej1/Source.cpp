
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include "bintree.h"
using namespace std;
const char EMPTY = '.';

typedef struct {
	bool equilibrio = true;
	int altura = 0;
} tSol;

tSol ejercicio(bintree<char> const& tree, int alt) {
	tSol sol;
	if (tree.empty()){
		sol.altura = 0;
		sol.equilibrio = true;
	}
/*	else if (!tree.left().empty() && tree.right().empty()) {
		sol = ejercicio(tree.left(), alt);
		sol.altura += 1;
	}
	else if (tree.left().empty() && !tree.right().empty()) {
		sol = ejercicio(tree.right(), alt);
		sol.altura += 1;
	}*/
	else {
		tSol izq, der;
		izq = ejercicio(tree.left(), alt++);
		der = ejercicio(tree.right(), alt++);
		int dif = abs(izq.altura - der.altura);
		if (dif <= 1 && (izq.equilibrio && der.equilibrio)) { sol.equilibrio = true; }
		else sol.equilibrio = false;
		sol.altura = 1 + std::max(der.altura, izq.altura);
		
	}
	return sol;
}
void resuelveCaso() {
	bintree<char> arbol;
	arbol = leerArbol(EMPTY);
	
		int alt = 0;
		tSol sol = ejercicio(arbol, alt);
		if (sol.equilibrio) std::cout << "SI" << endl;
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