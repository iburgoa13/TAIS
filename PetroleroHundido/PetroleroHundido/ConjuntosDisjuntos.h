//
//  ConjuntosDisjuntos.h
//
//  Implementaci�n de estructuras de partici�n o conjuntos disjuntos
//  con uni�n por tama�o y compresi�n de caminos
//
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2019  Alberto Verdejo
//

#ifndef CONJUNTOSDISJUNTOS_H_
#define CONJUNTOSDISJUNTOS_H_

#include <vector>
#include <iostream>

class ConjuntosDisjuntos {
public:

	// crea una estructura de partici�n con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(int N) : nelems(N), ncjtos(nelems), id(nelems, -1) {}

	// devuelve el n�mero de conjuntos disjuntos
	int num_cjtos() const { return ncjtos; }

	//  devuelve el identificador del conjunto que contiene a p
	int buscar(int p) const {
		if (id.at(p) < 0) // es una ra�z
			return p;
		else
			return id[p] = buscar(id[p]);
	}

	// unir los conjuntos que contengan a p y q
	void unir(int p, int q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la ra�z del mayor �rbol
			id[i] += id[j]; id[j] = int(i);
		}
		else {
			id[j] += id[i]; id[i] = int(j);
		}
		--ncjtos;
	}

	int tam(int p) const {
		return -id[buscar(p)];
	}

	bool unidos(int p, int q) const {
		return buscar(p) == buscar(q);
	}

protected:
	int nelems;           // los elementos son 0 .. nelems-1
	int ncjtos;           // n�mero de conjuntos disjuntos
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tama�o del conjunto de i

};


#endif
