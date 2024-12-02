#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;
class NodoB {
public:
    vector<int> claves;        // Almacena las claves
    vector<NodoB*> hijos;      // Punteros a los hijos
    bool esHoja;               // Indica si el nodo es hoja
    int t;                     // Mínimo grado (define el rango de claves por nodo)

    NodoB(int _t, bool _esHoja) {
        t = _t;
        esHoja = _esHoja;
        claves.resize(2 * t - 1);
        hijos.resize(2 * t);
    }
    friend class ArbolB;
};


#endif // NODO_H_INCLUDED
