//
//  Grafo.h
//
//  Implementaci�n de grafos no dirigidos
//
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2019  Alberto Verdejo
//

#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <vector>
#include <stdexcept>

using Adys = std::vector<int>;  // lista de adyacentes a un v�rtice

class Grafo {

	const int _V;   // n�mero de v�rtices
	int _E;   // n�mero de aristas
	std::vector<Adys> _ady;   // vector de listas de adyacentes

public:

	/**
	 * Crea un grafo con V v�rtices.
	 */
	Grafo(int v) : _V(v), _E(0), _ady(_V) {}

	/**
	 * Devuelve el n�mero de v�rtices del grafo.
	 */
	int V() const { return _V; }

	/**
	 * Devuelve el n�mero de aristas del grafo.
	 */
	int E() const { return _E; }


	/**
	 * A�ade la arista v-w al grafo.
	 * @throws invalid_argument si alg�n v�rtice no existe
	 */
	void ponArista(int v, int w) {
		if (v >= _V || w >= _V)
			throw std::invalid_argument("Vertice inexistente");
		++_E;
		_ady[v].push_back(w);
		_ady[w].push_back(v);
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
	 * Muestra el grafo en el stream de salida o (para depurar)
	 */
	void print(std::ostream & o = std::cout) const {
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
 * Para mostrar grafos por la salida est�ndar
 */
inline std::ostream & operator<<(std::ostream & o, Grafo const& g) {
	g.print(o);
	return o;
}


#endif /* GRAFO_H_ */
