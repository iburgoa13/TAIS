
// IKER BURGOA MUÑOZ

// comentario sobre la solución, incluyendo el análisis del coste
/*
Para el ejercicio he usado una cola y una busqueda en anchura
su coste es el numero de nodos que hay en la red  y su numero de aristas
porque recorres en anchura todas las posibilidades
O(E+V)
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include "Grafo.h"
#include <queue>
#include "ConjuntosDisjuntos.h"
using namespace std;
typedef struct {
	int nodo;
	int distancia;
} tNodo;


// esta es la clase que resuelve el problema  COMPLÉTALA
class NodoLejano {
public:
	NodoLejano(Grafo const& g, int inicio, int TTL, ConjuntosDisjuntos const &c) : marked(g.V(), false), nodosMarcados(0), aux(0) {
		marked[inicio] = true;
		tNodo nodos;
		nodos.distancia = 0;
		nodos.nodo = inicio;
		nodosMarcados++;
		bfs(g, nodos, TTL, aux);
	}

	int inalcanzables() const {
		return marked.size() - nodosMarcados;
	}
private:
	std::vector<bool> marked;
	std::vector<int> distTo;
	int nodosMarcados;
	
	
	int aux;
	void bfs(Grafo const& g, tNodo ini, int TTL, int &auxiliar) {
		queue<tNodo> q;
		tNodo aux;
		q.push(ini);
		while (!q.empty()) {
			auto a = q.front();
			q.pop();
			for (auto it : g.ady(a.nodo)) {						
				aux.distancia = a.distancia + 1;
				aux.nodo = it;
				if (!marked[it] && a.distancia< TTL) {
					marked[it] = true;
					nodosMarcados++;
					q.push(aux);
				}
			}
		}

	}
};
	

bool resuelveCaso() {

	int V, E;
	cin >> V >> E;
	if (!cin)
		return false;

	ConjuntosDisjuntos c(V);
	Grafo G(V);
	int u, v;
	for (int i = 0; i < E; ++i) {
		cin >> u >> v;
		c.unir(u - 1, v - 1);
		G.ponArista(u - 1, v - 1);
	}
	
	int K; // número de preguntas
	cin >> K;
	while (K--) {
		int origen, TTL;
		cin >> origen >> TTL;
		--origen;

		NodoLejano nl(G,origen, TTL,c);
		cout << nl.inalcanzables() << "\n";
	}
	cout << "---\n";
	return true;

}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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

