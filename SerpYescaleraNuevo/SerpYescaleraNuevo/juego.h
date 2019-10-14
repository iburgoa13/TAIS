#include "GrafoDirigido.h"
#include <queue>
#include <vector>
#ifndef JUEGO_H
#define JUEGO_H


class juego {
public:
	juego(GrafoDirigido &g, int n, int k, int ser, int esc) : dado(k), marked(g.V(), false), distTablero(g.V(), -1),
		distTo(g.V()) {
		leerTablero(g, ser, esc);
		bfs(g, n);
	}
	int minMovimientos(int n) {
		return distTo[n];
	}
private:
	int dado;
	std::vector<bool>marked;
	std::vector<int>distTo;
	std::vector<int>distTablero;
	void bfs(GrafoDirigido &g, int n) {
		std::queue<int> cola;
		cola.push(n);
		distTo[n] = 0;
		marked[n] = 0;
		while (!cola.empty()) {
			auto aux = cola.front();
			cola.pop();
			for (auto t : g.ady(aux)) {
				if (!marked[t]) {
					marked[t] = true;
					distTo[t] = distTo[aux] + 1;
					cola.push(t);
				}
			}
		}
	}
	void leerTablero(GrafoDirigido &g, int ser, int esc) {
		int v, w;
		for (int i = 0; i < ser; i++) {
			std::cin >> v >> w;
			distTablero[v - 1] = w - 1;
		}
		for (int i = 0; i < esc; i++) {
			std::cin >> v >> w;
			distTablero[v - 1] = w - 1;
		}
		for (int i = 0; i < g.V(); i++) {
			for (int j = i+1; j <= g.V() - 1 && j <= dado + i; j++) {
				//std::cin >> v >> w;
				if (distTablero[j] == -1) {
					g.ponArista(i, j);
				}
				else g.ponArista(i, distTablero[j]);
			}
		}
	}
};
#endif