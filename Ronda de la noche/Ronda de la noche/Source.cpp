
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <queue>
#include <climits>
#include "Matriz.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
const std::vector<std::pair<int, int>> direcciones = { {1,0}, {0,1},{0,-1},{-1,0} };

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
/*
• ‘#’: Una pared.
• ‘.’: Una casilla libre.
• ‘E’: La casilla donde est´a la entrada al jard´ın-laberinto.
• ‘P’: La casilla donde est´a la puerta principal de la casa.
• k, con 0 ≤ k ≤ 9: Casilla que alberga un sensor CAT-k.
*/
const char sensores = 'S';
typedef struct {
	int x;
	int y;
	int valor;
} tSensores;

void ejercicio(Matriz<bool> &marked, int ancho, int alto, std::pair<int, int> ini, std::pair<int, int> fin,Matriz<char>&mapa) {
	Matriz<int>distTo(alto, ancho, 0);
	std::queue<std::pair<int, int>> q;
	std::pair<int, int > aux;
	q.push(ini);
	marked[ini.first][ini.second] = true;
	distTo[ini.first][ini.second] = 0;
	while (!q.empty()) {
		aux = q.front();
		q.pop();
		for (auto dir : direcciones) {
			int ni = aux.first + dir.first;
			int nj = aux.second + dir.second;
			if (marked.posCorrecta(ni,nj) && !marked[ni][nj]) {
				marked[ni][nj] = true;
				distTo[ni][nj] = 1 + distTo[aux.first][aux.second];
				q.push({ ni,nj });
			}
		}
	}
	if (marked[fin.first][fin.second] && mapa[fin.first][fin.second]!='+') std::cout << distTo[fin.first][fin.second] << "\n";
	else std::cout << "NO\n";
}


void colocaSensor(std::queue<tSensores> & sensor, Matriz<bool>&marked, Matriz<char>&mapa) {
	while (!sensor.empty()) {
		tSensores aux = sensor.front();
		sensor.pop();
		int x = aux.x;
		int y = aux.y;
		int i = 0;
		marked[x][y] = true;
		mapa[x][y] = '+';
		while (i < aux.valor && marked.posCorrecta(x-1, y) && mapa[x-1][y]!='#') {
			marked[x-1][y] = true;
			mapa[x-1][y] = '+';
			x--;
			i++;
		}
		x = aux.x;
		i = 0;
		while (i < aux.valor && marked.posCorrecta(x + 1, y) && mapa[x + 1][y]!='#') {
			marked[x+1][y] = true;
			mapa[x+1][y] = '+';
			x++; i++;
		}
		x = aux.x;
		int j = 0;
		while (j < aux.valor && marked.posCorrecta(x, y - 1) && mapa[x][y-1]!='#') {
			marked[x][y - 1] = true;
			mapa[x][y-1] = '+';
			y--; j++;
		}
		j = 0;
		y = aux.y;
		while (j < aux.valor && marked.posCorrecta(x, y + 1) && mapa[x][y+1]!='#') {
			marked[x][y + 1] = true;
			mapa[x][y+1] = '+';
			y++; j++;
		}
	}

}
void resuelveCaso() {
	
	int n;
	char caracter;
	int ancho, alto;
	
	std::cin >> n;
	std::pair<int, int> inicio, fin;
	std::queue<tSensores> sensores;
	std::vector<std::vector<char>> mapa;
	for (int i = 0; i < n; i++) {
		std::cin >> ancho >> alto;
		Matriz<bool>marked(alto,ancho,false);
		Matriz<char>mapa(alto, ancho);
		std::cin.get();		for (int j = 0; j < alto; j++) {
			for (int w = 0; w < ancho; w++) {
				std::cin >> caracter;
				mapa[j][w] = caracter;
				if (caracter == '#') {
					marked[j][w] = true;
				}
				if (caracter >= 48 && caracter <= 57) {
					int valor = caracter - 48;
					sensores.push({ j,w,valor });
					marked[j][w] = true;
				}
				if (caracter == 'P') {
					fin = { j,w };
				}
				if (caracter == 'E') {
					inicio = { j,w };
				}
			}
		}
		colocaSensor(sensores, marked,mapa);
		if (mapa[inicio.first][inicio.second]== '+')std::cout << "NO\n";
		else if( mapa[fin.first][fin.second] == '+') std::cout << "NO\n";
		else ejercicio(marked, ancho, alto, inicio, fin,mapa);
	}
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}