// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
typedef struct {
	int uno;
	int otro;
	int valor;
} tBicis;
class Bicicleta {
public:
	Bicicleta(GrafoValorado<int> const &GV) : numBicis(0) , marked(GV.V(),false), costeminimo(0){
		visit(GV, 0);
		while (numBicis != marked.size()-1 && !pq.empty()) {
			auto bici = pq.top();
			pq.pop();
			int v = bici.uno();
			int w = bici.otro(v);
			if (!marked[v] || !marked[w]) {
				costeminimo += bici.valor();
				numBicis++;
				if (!marked[v]) visit(GV, v);
				if (!marked[w]) visit(GV, w);
			}
		}
	}
	int costeMinimo() const {
		return costeminimo;
	}
	bool HayCamino() {
		return numBicis == marked.size() - 1;
	}
private:
	int numBicis;
	std::vector<bool>marked;
	int costeminimo;
	//PriorityQueue<Arista<int>> pq;

	//PriorityQueue<Arista<int>, std::vector<Arista<int>, std::greater<Arista<int>>>> pq;
	PriorityQueue < Arista<int>> pq;
	//priority_queue<Arista<int>, std::vector<Arista<int>>, std::greater<Arista<int>>> pq;
	void visit(GrafoValorado<int> GV, int v) {
		marked[v] = true;
		for (auto a : GV.ady(v)) {
			if (!marked[a.otro(v)]) {
				pq.push(a);
			}
		}
	}
};
void ejercicio(const int &isla, const int &puente) {
	PriorityQueue<tBicis> cola;
	GrafoValorado<int> grafo(isla);
	for (int i = 0; i < puente; i++) {
		int v, w, valor;
		std::cin >> v >> w >> valor;
		grafo.ponArista({ v - 1,w - 1,valor });
	}
	Bicicleta bici(grafo);
	if (bici.HayCamino()) {
		std::cout << bici.costeMinimo() << "\n";
	}
	else std::cout << "No hay puentes suficientes\n";
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int isla;
	
	if (std::cin >> isla) {
		int puentes;
		std::cin >> puentes;
		ejercicio(isla, puentes);
		return true;
	}
		// fin de la entrada
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