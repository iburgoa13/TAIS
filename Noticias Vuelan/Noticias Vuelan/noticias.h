#include "Grafo.h"
#include <vector>
#ifndef  noticia_h
#define noticia_h


class noticia {
public:
	noticia(Grafo const &g) : max(0),marked(g.V(),false),total(g.V(),0) {
		for (int i = 0; i < g.V(); i++) {
			total[i] = g.ady(i).size();
			max += total[i];
			marked[i] = true;
			funcion(i,g);
			//marked[i] = false;
			max++;
			
			std::cout << max << " ";
			max = 0;
			//desmarcar();
		}
	}
	std::vector<int> totalNoticias() {
		return total;
	}
private:
	int max;
	std::vector<int> total;
	std::vector<bool> marked;
	void desmarcar() {
		for (int i = 0; i < marked.size(); i++) {
			marked[i] = false;
		}
	}
	void fun(int i, Grafo g) {
		for (int x : g.ady(i)) {
			if (marked[x]) {

			}
		}
	}
	void funcion(int &i, Grafo const &g) {
		for (int w : g.ady(i)) {
			if (!marked[w]) {
				marked[w] = true;
				total[w] = g.ady(w).size()-1;
				//max += total[w]-1;
				funcion(w, g);
			}
			//else if(total[w]!=0) max += total[w];
		}
		
	}
};
#endif // ! noticia_h
