/*
 * Grafo.cpp
 *
 *  Created on: 29/03/2014
 *      Author: Emmanuel
 */
#include "Grafo.h"

Grafo::Grafo() {
	nodo = 0;
	longitud = 0;
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
	while (tmp)
		if (tmp->id == id)
			return tmp;
		else
			tmp = tmp->siguiente;
	return tmp;
}

void Grafo::agregarNodo(int id) {
	if (!this->buscarNodo(id)) {
		Nodo * nuevoNodo = new Nodo(id);
		if (this->vacia())
			nodo = nuevoNodo;
		else {
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
	if (this->buscarNodo(id)) {
		if (nodo->id == id) { //cabeza
			if (nodo->siguiente) {
				Nodo * borrar = nodo;
				nodo = nodo->siguiente;
				borrar->siguiente = 0;
				delete borrar;
			} else {
				delete nodo;
				nodo = 0;
			}
		} else {
			Nodo * tmp = nodo;
			while (tmp->siguiente && tmp->siguiente->id != id)
				tmp = tmp->siguiente;
			Nodo * borrar = tmp->siguiente;
			tmp->siguiente = tmp->siguiente->siguiente;
			borrar->siguiente = 0;
			delete borrar;
		}
		this->borrarAristasAsociadas(id);
	}
}

void Grafo::borrarAristasAsociadas(int id){
	if(!vacia()){
		Nodo * tmp = nodo;
		while(tmp){
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
	longitud = 0;
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
	if (!this->buscarArista(destino)) {
		Arista * nuevaArista = new Arista(destino, peso);
		if (this->vacia())
			this->arista = nuevaArista;
		else {
			nuevaArista->siguiente = this->arista;
			this->arista = nuevaArista;
		}
	}
}

void Grafo::Nodo::borrarArista(int destino) {
	if (this->buscarArista(destino)) {
		if (arista->destino == destino) { //cabeza
			if (arista->siguiente) {
				Arista * borrar = arista;
				arista = arista->siguiente;
				borrar->siguiente = 0;
				delete borrar;
			} else {
				delete arista;
				arista = 0;
			}
		} else {
			Arista * tmp = arista;
			while (tmp->siguiente && tmp->siguiente->destino != destino)
				tmp = tmp->siguiente;
			Arista * borrar = tmp->siguiente;
			tmp->siguiente = tmp->siguiente->siguiente;
			borrar->siguiente = 0;
			delete borrar;
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
