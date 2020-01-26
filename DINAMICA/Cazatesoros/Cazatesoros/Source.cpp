#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

template <typename Object>
class Matriz {
public:
	// crea una matriz con fils filas y cols columnas,
	// con todas sus celdas inicializadas al valor e
	Matriz(int fils, int cols, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}

	// operadores para poder utilizar notación M[i][j]
	std::vector<Object> const& operator[](int f) const {
		return datos[f];
	}
	std::vector<Object> & operator[](int f) {
		return datos[f];
	}

	// métodos que lanzan una excepción si la posición no existe
	Object const& at(int f, int c) const {
		return datos.at(f).at(c);
	}
	Object & at(int f, int c) { // este método da problemas cuando Object == bool
		return datos.at(f).at(c);
	}

	int numfils() const { return datos.size(); }
	int numcols() const { return numfils() > 0 ? datos[0].size() : 0; }

	bool posCorrecta(int f, int c) const {
		return 0 <= f && f < numfils() && 0 <= c && c < numcols();
	}

private:
	std::vector<std::vector<Object>> datos;
};
typedef struct {
	int dist;
	int cant;
} tCofre;
bool resuelveCaso() {
	int T;
	std::cin >> T;
	if (!std::cin)return false;
	int N;
	std::cin >> N;
	Matriz<int> mapaTesoro(N + 1, T + 1, 0);
	int i = N;
	tCofre cofre;
	std::vector<tCofre> cofres;
	while (i--) {
		std::cin >> cofre.dist >> cofre.cant;
		cofre.dist = cofre.dist * 3;
		cofres.push_back(cofre);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			if (cofres[i - 1].dist > j) {
				mapaTesoro[i][j] = mapaTesoro[i - 1][j];
			}
			else {
				mapaTesoro[i][j] = std::max(mapaTesoro[i - 1][j], mapaTesoro[i - 1][j - cofres[i - 1].dist] + cofres[i - 1].cant);
			}
		}
	}
	std::cout << mapaTesoro[N][T] << "\n";
	std::vector<bool>cofresARecoger(N,false);
	int numCofres = 0;
	int valor = T;
	for (int i = 1; i <= N; i++) {
		if (mapaTesoro[i][valor] == cofres[i - 1].cant) {
			cofresARecoger[i - 1] = true;
			valor = valor - cofres[i - 1].dist;
			numCofres++;
		}
	}
	std::vector<int>cofresRecogidos;
	std::cout << numCofres << "\n";
	for (int i = 0; i < N; i++) {
		if (cofresARecoger[i]) {
			std::cout << cofres[i].dist / 3 << " " << cofres[i].cant << "\n";
		}
	}
	std::cout <<"---\n";
	return true;
}
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}