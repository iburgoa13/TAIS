
/*
Iker Burgoa Muñoz
Ana Corral Descargue
*/

// comentario sobre la solución, incluyendo el análisis del coste

#include <iostream>
#include "PriorityQueue.h"
#include <fstream>
#include <algorithm>
using namespace std;

typedef struct {
	bool repe;
	int inicio;
	int fin;
	int repeticion;
} tPeriodo;
bool operator<(const tPeriodo& a, const tPeriodo& b) {
	return (a.inicio < b.inicio);
}

/*
P = tPeriodo
N = El numero de vueltas que se de hasta cumplir un tiempo t
 NLogP
 La idea es una cola de mínimos donde sacamos el top  y comparamos si el final de un trabajo
 se encuentra entre el inicio y el final del top de la cola. En ese caso entra en conflicto.
 Si es periodico sumamos su periodo a los tiempos y los introducimos en la cola de nuevo hasta que
 se llege al tiempo t
*/
void resuelve(int n, int m, int t) {
	PriorityQueue<tPeriodo> cola;
	int ocupado = 0;
	bool conflicto = false;
	int ini, fin, per;
	for (int i = 0; i < n; i++) {
		std::cin >> ini >> fin;
		cola.push({false, ini,fin,0 });
	}
	for (int i = 0; i < m; i++) {
		std::cin >> ini >> fin >> per;
		cola.push({true, ini,fin,per });
	}

	while (!conflicto && !cola.empty() && cola.top().inicio < t) {
		tPeriodo primero;
		primero = cola.top();
		cola.pop();
		conflicto = primero.inicio < ocupado;
		ocupado = primero.fin;
		if (primero.repe) {
			cola.push({ true,primero.inicio + primero.repeticion,primero.fin + primero.repeticion,primero.repeticion });
		}

	}
	if (conflicto) std::cout << "SI\n";
	else std::cout << "NO\n";
}
bool resuelveCaso() {

	// leemos la entrada
	int N, M, T;
	cin >> N >> M >> T;
	if (!cin)
		return false;

	// leer el resto del caso y resolverlo

	resuelve(N, M, T);
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
