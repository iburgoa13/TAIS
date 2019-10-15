#include <vector>
#include <algorithm>
#include <climits>
#include "ConjuntosDisjuntos.h"
#ifndef PETROLEROS_HUNDIDOS_H
#define PETROLEROS_HUNDIDOS_H

const std::vector<std::pair<int, int>> direcciones=
{ {1,0} , {0,1}, {-1,0}, {0,-1}, {1,1} , {1,-1}, {-1,1}, {-1,-1} };
class PetroleroHundido {
public:
	PetroleroHundido(std::vector<std::string> const &tablero, int f, int c)
		: filas(f), columnas(c),
		conjunto(f*c), marked(f,std::vector<bool>(c,false)), hundidos(0) {
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				//si he encontrado una mancha y no esta marcada
				if (tablero[i][j] == '#' && !marked[i][j]) {
					int aux = 0;
					dfs(tablero, i, j, aux);
					hundidos = std::max(hundidos, aux);
				}
			}
		}
	}
	int getHundidos() const {
		return hundidos;
	}
	/*
	Dentro del tablero uno con conjuntos la nueva contaminada y la uno a uno a todos los que existan a su alrededor
	y con conjuntos disjuntos unes todos a un mismo id
	*/
	void nuevo(std::vector<std::string>const &tablero, int i, int j) {
		int v = i * columnas + j;
		bool exist = false;
		for (auto dir : direcciones) {
			int ni = i + dir.first;
			int nj = j + dir.second;
			if (posicionCorrecta(ni, nj) && tablero[ni][nj] == '#') {
				int w = ni * columnas + nj;
				conjunto.unir(v, w);
				hundidos = std::max(conjunto.tam(v), hundidos);
				exist = true;
			}
		}
		if (!exist) hundidos = std::max(conjunto.tam(v), hundidos);
	}
private:
	std::vector<std::vector<bool>>marked;
	ConjuntosDisjuntos conjunto;
	int hundidos;
	int filas, columnas;
	bool posicionCorrecta(int i, int j) {
		return i >= 0 && i < filas && j >= 0 && j < columnas;
	}
	void dfs(const std::vector<std::string> &tablero,
		int i, int j, int &aux) {
		marked[i][j] = true;
		aux++;
		for (auto dir : direcciones) {
			int v = i * columnas + j;
			int ni = i + dir.first;
			int nj = j + dir.second;
			if (posicionCorrecta(ni,nj) &&tablero[ni][nj] == '#' && !marked[ni][nj]) {
				int w = ni * columnas + nj;
				conjunto.unir(v, w);
				dfs(tablero, ni, nj, aux);
			}
		}

	}
};
#endif