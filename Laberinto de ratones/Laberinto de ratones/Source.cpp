#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
const int INF = 1000000000;
class ratones {
public:
	/*
	algoritmo de Dijsktra --> O(ElogV)
	*/
	ratones(GrafoDirigidoValorado<int> &G, int S): distTo(G.V(),INF),pq(G.V())
	{
		/*
		Grafo inverso porque nos interesa saber el valor que hay en las celdas donde hay ratones desde la salida para calcular los tiempos
		*/
		auto gi = G.inverso();
		distTo[S] = 0;
		pq.push(S, 0);
		while (!pq.empty()) {
			int e = pq.top().elem;
			pq.pop();
			for (auto it : gi.ady(e)) {
				relax(it);
			}
		}
	}
	int calculoRatones(int s, int tiempo) {
		int cont = 0;
		/*
		i != S porque tienes que diferenciar la salida, que no cuenta
		*/
		for (int i = 0; i < distTo.size(); i++) {
			if (i != s && distTo[i] <= tiempo) {
				cont++;
			}
		}
		return cont;
	}
private:
	std::vector<int> distTo;
	IndexPQ<int> pq;
	void relax(const AristaDirigida<int> &it) {
		int v = it.from();
		int w = it.to();
		if (distTo[w] > distTo[v] + it.valor()) {
			distTo[w] = distTo[v] + it.valor();
			pq.update(w, distTo[w]);
		}
	}
};
bool resuelveCaso() {
	int N;
	if (std::cin >> N) {
		int S, T, P;
		std::cin >> S >> T >> P;
		int A, B, valor;
		GrafoDirigidoValorado<int>grafo(N);
		for (int i = 0; i < P; i++) {
			std::cin >> A >> B >> valor;
			grafo.ponArista({ A - 1,B - 1,valor });
		}
		ratones raton(grafo, S - 1);
		int sol = raton.calculoRatones(S - 1, T);
		std::cout << sol << "\n";
		return true;
	}
	return false;
}
int main() {
	// Para la entrada por fichero.
		// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.in");
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