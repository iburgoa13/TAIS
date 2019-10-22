#include <vector>
#include "GradoValorado.h"
#ifndef CAMIONES_H
#define CAMIONES_H
class Camiones {
public:
	Camiones(GrafoValorado<int> const &grafo, int ori,int peso) : marked(grafo.V(),false) {
		dfs(grafo, ori, peso);
	}
	bool destino(int n) {
		return marked[n];
	}
private:
	std::vector<bool> marked;
	void dfs(GrafoValorado<int> const &grado, int ori, int peso) {
		marked[ori] = true;
		for (auto it : grado.ady(ori)) {		
			if (!marked[it.otro(ori)]) {
				if (peso <= it.valor()) {
					dfs(grado, it.otro(ori), peso);
				}
			}
		}
	}
};
#endif