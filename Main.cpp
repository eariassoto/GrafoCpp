#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
   Grafo * grafo = new Grafo();
   grafo->agregarNodo(2);
   grafo->agregarNodo(34);
   grafo->agregarNodo(4);
   grafo->agregarNodo(5);
   grafo->agregarNodo(55);
   grafo->agregarNodo(1);
   grafo->agregarNodo(106);
   grafo->agregarNodo(21);
   grafo->agregarNodo(5); // no lo agrega, nodo ya existe

   grafo->agregarArista(5, 106, 4);
   grafo->agregarArista(2, 10, 76); // no la agrega, destino no existe
   grafo->agregarArista(2, 5, 10);
   grafo->agregarArista(2, 5, 4); // no la agrega, destino ya existe
   grafo->agregarArista(2, 34, 1);
   grafo->agregarArista(34, 4, 10);
   grafo->agregarArista(34, 106, 3);
   grafo->agregarArista(34, 5, 15);
   grafo->agregarArista(34, 2, 15);

   cout << *grafo << endl;

   grafo->borrarNodo(21);
   grafo->borrarNodo(1);
   grafo->borrarNodo(5);

   cout << *grafo << endl;

   grafo->borrarArista(34, 2);
   grafo->borrarArista(34, 106);

   cout << *grafo << endl;
   return 0;
}
