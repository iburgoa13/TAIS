#include "grafo.h"
#include <vector>
#ifndef bipartito_h
#define bipartito_h

class bipartito {
public:
	bipartito(Grafo const &g) :
		marked(g.V(), false),
		color(g.V()), bipar(true){
		for (int x = 0; x < g.V(); x++) {

			if (!marked[x]) {
				color[x] = true;
				dfs(g, x);
			}
	}
	}
	bool esBipartito() {
		return bipar;
	}
private:
	std::vector<bool> marked;
	std::vector<bool> color;
	bool bipar;
	void dfs(Grafo const &g, int x) {
		marked[x] = true;
		for (int i : g.ady(x)) {
			if (!marked[i]) {
				color[i] = !color[x];
				dfs(g, i);
				
			}
			else if (color[i] == color[x]) {
				bipar = false;
			}
		}
	}
};
#endif