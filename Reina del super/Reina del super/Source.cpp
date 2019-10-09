// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;
typedef struct {
	long long int tiempo=0;
	long long int orden=0;
} tCaja;
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool operator<(tCaja const& a, tCaja const& b) {
	return ((a.tiempo < b.tiempo) || (a.tiempo == b.tiempo && (a.orden < b.orden)));

}
void ejercicio(int c, int n) {
	tCaja caja;
	int tiempo;
	PriorityQueue<tCaja> cajero;
	for (int i = 0; i < c; i++) {
		cajero.push({ 0,i + 1 });
	}
	for (int j = 0; j < n; j++) {
		std::cin >> tiempo;
		caja = cajero.top();
		cajero.pop();
		caja.tiempo += tiempo;
		cajero.push(caja);
	}
	std::cout << cajero.top().orden << "\n";
}
bool resuelveCaso() {
	int n, c;
	std::cin >> n >> c;
	if (n == 0 && c == 0) return false;
	else {
		ejercicio(n,c);
		return true;
	}

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
