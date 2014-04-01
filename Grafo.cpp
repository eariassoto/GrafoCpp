/*
 * Grafo.cpp
 *
 *  Created on: 29/03/2014
 *      Author: Emmanuel
 */
#include "Grafo.h"

Grafo::Grafo() {
	nodo = 0;
}

Grafo::~Grafo() {
	if (this->nodo)
		delete this->nodo;
}

ostream& operator<<(ostream & salida, const Grafo& grafo) {
	salida << "Grafo = {";
	if (grafo.nodo) {
		salida << "\n";
		salida << *(grafo.nodo); // invoca al operator<<(cout, const Nodo& primero)
		salida << "\n";
	}
	salida << "}";
	return salida;
}

bool Grafo::buscarNodo(int id) {
	Nodo * tmp = nodo;
	while (tmp)
		if (tmp->id == id)
			return true;
		else
			tmp = tmp->siguiente;
	return false;
}

bool Grafo::vacia() {
	return !nodo;
}

Grafo::Nodo * Grafo::obtenerNodo(int id) {
	Nodo * tmp = nodo;
	bool encontrado = false;
	while (!encontrado && tmp)
		if (tmp->id == id)
			encontrado = true;
		else
			tmp = tmp->siguiente;
	return (encontrado) ? tmp : 0;
}

void Grafo::agregarNodo(int id) {
	if (this->vacia()) {
		Nodo * nuevoNodo = new Nodo(id);
		nodo = nuevoNodo;
	} else {
		if (!this->buscarNodo(id)) {
			Nodo * nuevoNodo = new Nodo(id);
			nuevoNodo->siguiente = nodo;
			nodo = nuevoNodo;
		}
	}
}

void Grafo::agregarArista(int idNodo, int destino, int peso) {
	if (this->buscarNodo(idNodo) && this->buscarNodo(destino))
		this->obtenerNodo(idNodo)->agregarArista(destino, peso);
}

void Grafo::borrarNodo(int id) {
	if (!vacia()) {
		if (nodo->id == id) { //cabeza
			Nodo * borrar = nodo;
			nodo = nodo->siguiente;
			borrar->siguiente = 0;
			delete borrar;
		} else {
			Nodo * tmp = nodo;
			while (tmp->siguiente && tmp->siguiente->id != id)
				tmp = tmp->siguiente;
			if (tmp->siguiente && tmp->siguiente->id == id) {
				Nodo * borrar = tmp->siguiente;
				tmp->siguiente = tmp->siguiente->siguiente;
				borrar->siguiente = 0;
				delete borrar;
			}
		}
		this->borrarAristasAsociadas(id);
	}
}

void Grafo::borrarAristasAsociadas(int id) {
	if (!vacia()) {
		Nodo * tmp = nodo;
		while (tmp) {
			tmp->borrarArista(id);
			tmp = tmp->siguiente;
		}
	}
}

void Grafo::borrarArista(int idNodo, int destino) {
	if (this->buscarNodo(idNodo))
		this->obtenerNodo(idNodo)->borrarArista(destino);
}

Grafo::Nodo::Nodo(int id) {
	this->id = id;
	siguiente = 0;
	arista = 0;
}

Grafo::Nodo::~Nodo() {
	if (this->arista)
		delete this->arista;
	if (this->siguiente)
		delete this->siguiente;
}

ostream& operator<<(ostream & salida, const Grafo::Nodo& nodo) {
	salida << nodo.id;
	if (nodo.arista)
		salida << *(nodo.arista);
	if (nodo.siguiente) {
		salida << "\n";
		salida << *(nodo.siguiente);
	}
	return salida;
}

bool Grafo::Nodo::buscarArista(int destino) {
	Arista * tmp = arista;
	while (tmp)
		if (tmp->destino == destino)
			return true;
		else
			tmp = tmp->siguiente;
	return false;
}

bool Grafo::Nodo::vacia() {
	return !arista;
}

void Grafo::Nodo::agregarArista(int destino, int peso) {
	if (this->vacia()) {
		Arista * nuevaArista = new Arista(destino, peso);
		arista = nuevaArista;
	} else {
		if (!this->buscarArista(destino)) {
			Arista * nuevaArista = new Arista(destino, peso);
			nuevaArista->siguiente = this->arista;
			this->arista = nuevaArista;
		}
	}
}

void Grafo::Nodo::borrarArista(int destino) {
	if (!vacia()) {
		if (arista->destino == destino) { //cabeza
			Arista * borrar = arista;
			arista = arista->siguiente;
			borrar->siguiente = 0;
			delete borrar;
		} else {
			Arista * tmp = arista;
			while (tmp->siguiente && tmp->siguiente->destino != destino)
				tmp = tmp->siguiente;
			if (tmp->siguiente && tmp->siguiente->destino == destino) {
				Arista * borrar = tmp->siguiente;
				tmp->siguiente = tmp->siguiente->siguiente;
				borrar->siguiente = 0;
				delete borrar;
			}
		}
	}
}

Grafo::Nodo::Arista::Arista(int d, int p) {
	this->destino = d;
	this->peso = p;
	siguiente = 0;
}

Grafo::Nodo::Arista::~Arista() {
	if (this->siguiente)
		delete this->siguiente;
}

ostream& operator<<(ostream & salida, const Grafo::Nodo::Arista& arista) {
	salida << " Aristas: ";
	salida << "(" << arista.destino << ", " << arista.peso << ")";
	if (arista.siguiente) {
		salida << ", ";
		salida << *(arista.siguiente);
	}
	return salida;
}
