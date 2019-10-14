//
//  GrafoDirigido.h
//
//  Implementaci�n de grafos dirigidos
//
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2019  Alberto Verdejo
//

#ifndef GRAFODIRIGIDO_H_
#define GRAFODIRIGIDO_H_

#include <iostream>
#include <stdexcept>
#include <vector>

using Adys = std::vector<int>;  // lista de adyacentes a un v�rtice

class GrafoDirigido {

	const int _V;   // n�mero de v�rtices
	int _E;   // n�mero de aristas
	std::vector<Adys> _ady;   // vector de listas de adyacentes

public:

	/**
	 * Crea un grafo dirigido con V v�rtices.
	 */
	GrafoDirigido(int v) : _V(v), _E(0), _ady(_V) {}


	/**
	 * Devuelve el n�mero de v�rtices del grafo.
	 */
	int V() const { return _V; }


	/**
	 * Devuelve el n�mero de aristas del grafo.
	 */
	int E() const { return _E; }


	/**
	 * A�ade la arista dirigida v-w al grafo.
	 * @throws invalid_argument si alg�n v�rtice no existe
	 */
	void ponArista(int v, int w) {
		if (v >= _V || w >= _V)
			throw std::invalid_argument("Vertice inexistente");
		++_E;
		_ady[v].push_back(w);
	}


	/**
	 * Comprueba si hay arista de u a v.
	 */
	bool hayArista(int u, int v) const {
		for (auto w : _ady[u])
			if (w == v) return true;
		return false;
	}


	/**
	 * Devuelve la lista de adyacencia de v.
	 * @throws invalid_argument si v no existe
	 */
	Adys const& ady(int v) const {
		if (v >= _V)
			throw std::invalid_argument("Vertice inexistente");
		return _ady[v];
	}


	/**
	 * Devuelve el grafo dirigido inverso.
	 */
	GrafoDirigido inverso() const {
		GrafoDirigido R(_V);
		for (auto v = 0; v < _V; ++v) {
			for (auto w : _ady[v]) {
				R.ponArista(w, v);
			}
		}
		return R;
	}


	/**
	 * Muestra el grafo en el stream de salida o (para depurar)
	 */
	void print(std::ostream& o = std::cout) const {
		o << _V << " v�rtices, " << _E << " aristas\n";
		for (auto v = 0; v < _V; ++v) {
			o << v << ": ";
			for (auto w : _ady[v]) {
				o << w << " ";
			}
			o << "\n";
		}
	}

};

/**
 * Para mostrar grafos por la salida est�ndar.
 */
inline std::ostream & operator<<(std::ostream & o, GrafoDirigido const& g) {
	g.print(o);
	return o;
}


#endif /* GRAFODIRIGIDO_H_ */
