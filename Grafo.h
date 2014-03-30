/*
 * Grafo.h
 *
 *  Created on: 29/03/2014
 *      Author: Emmanuel
 */

#ifndef GRAFO_H_
#define GRAFO_H_
#include <iostream>
using namespace std;
class Grafo {
public:

	Grafo();
	Grafo(const Grafo&);
	~Grafo();

	friend ostream& operator << (ostream&, const Grafo&);

	class Nodo {
	public:
		Nodo(int);
		~Nodo();

		friend ostream& operator << (ostream&, const Nodo&);

		class Arista {
		public:
			Arista(int, int);
			~Arista();
			friend ostream& operator << (ostream&, const Arista&);

			int destino;
			int peso;
			Arista * siguiente;
		};

		int id;
		int longitud;
		Nodo * siguiente;
		Arista * arista;

		bool buscarArista(int);
		bool vacia();
		void agregarArista(int, int);
		void borrarArista(int);
	};

	bool buscarNodo(int);
	Grafo::Nodo * obtenerNodo(int);
	bool vacia();
	void agregarNodo(int);
	void agregarArista(int, int, int);
	void borrarNodo(int);
	void borrarAristasAsociadas(int);
	void borrarArista(int, int);

private:

	Nodo * nodo;
	int longitud;
};

#endif /* GRAFO_H_ */
