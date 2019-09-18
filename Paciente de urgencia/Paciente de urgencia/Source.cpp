// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;
typedef struct {
	string nombre;
	long long int gravedad;
	long long int contador;
} tPaciente;
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool operator<(tPaciente const& a, tPaciente const& b) {
	return ((a.gravedad > b.gravedad) || (a.gravedad == b.gravedad && (a.contador < b.contador)));
		
}
void ejercicio(int n) {
	char opcion;
	tPaciente paciente;
	tPaciente aux;
	PriorityQueue<tPaciente> cola;
	paciente.contador = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> opcion;
		if (opcion == 'I') {
			std::cin >> paciente.nombre >> paciente.gravedad;
			paciente.contador++;
			cola.push(paciente);
		
		}
		else {
			aux = cola.top();
			std::cout << aux.nombre << "\n";
			cola.pop();
		}
	}
}
bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;
	else {
		ejercicio(n);
		std::cout << "---\n";
		return true;
	}

}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
