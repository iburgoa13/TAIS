#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include"GrafoValorado.h"
#include "IndexPQ.h"
const int INF = 100000000;

class Navegacion {
public:
	Navegacion(const GrafoDirigidoValorado<int> &grafo,
		std::vector<int> &dist) :
		marked(dist.size(), false), distTo(dist.size(), INF),
		pq(grafo.V())
	{
	
		distTo[0] = 0;
		pq.push(0, 0);
		while (!pq.empty()) {
			auto e = pq.top().elem;
			pq.pop();
			for (auto it : grafo.ady(e)) {
				relax(it);
			}
		}
	}
	bool hayCamino() {
		if (distTo[distTo.size() - 1] == INF)return false;
		else return true;
	}
	int camino() {
		return distTo[distTo.size() - 1];
	}
private:
	IndexPQ<int> pq;
	std::vector<bool>marked;
	std::vector<int>distTo;
	void relax(AristaDirigida<int> &a) {
		int v = a.from();
		int w = a.to();
		if (distTo[w] > distTo[v] + a.valor()) {
			distTo[w] = distTo[v] + a.valor();
			pq.update(w, distTo[w]);
		}
	}
};
bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0) return false;
	std::vector<int> cargarPagina(N);
	int carga;
	for (int i = 0; i < N; i++) {
		std::cin >> carga;
		cargarPagina.at(i) = carga;
	}
	int M;
	std::cin >> M;
	int v, w, valor;
	GrafoDirigidoValorado<int> grafo(N);
	for (int i = 0; i < M; i++) {
		std::cin >> v >> w >> valor;
		grafo.ponArista({ v - 1,w - 1,cargarPagina[w - 1] + valor });
	}
	Navegacion navegando(grafo, cargarPagina);
	if (navegando.hayCamino()) {
		std::cout << navegando.camino() + cargarPagina.at(0) << "\n";
	}
	else std::cout << "IMPOSIBLE\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}