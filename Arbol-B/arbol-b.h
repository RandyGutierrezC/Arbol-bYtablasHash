#ifndef ARBOL-B_H_INCLUDED
#define ARBOL-B_H_INCLUDED
#include"Nodo.h"
class ArbolB {
private:
    NodoB* raiz; // Nodo raíz
    int t;       // Mínimo grado

    void dividirHijo(NodoB* nodo, int idx, NodoB* hijo);
    void insertarNoLleno(NodoB* nodo, int clave);

public:
    ArbolB(int _t) {
        raiz = nullptr;
        t = _t;
    }

    void insertar(int clave);
    void mostrar();
    void mostrarNodo(NodoB* nodo, int nivel);
};

// Método para insertar una clave en un nodo no lleno
void ArbolB::insertarNoLleno(NodoB* nodo, int clave) {
    int i = nodo->claves.size() - 1;

    if (nodo->esHoja) {
        while (i >= 0 && clave < nodo->claves[i]) {
            i--;
        }
        nodo->claves.insert(nodo->claves.begin() + i + 1, clave);
    } else {
        while (i >= 0 && clave < nodo->claves[i]) {
            i--;
        }
        i++;
        if (nodo->hijos[i]->claves.size() == 2 * t - 1) {
            dividirHijo(nodo, i, nodo->hijos[i]);
            if (clave > nodo->claves[i]) {
                i++;
            }
        }
        insertarNoLleno(nodo->hijos[i], clave);
    }
}

// Método para dividir un hijo lleno
void ArbolB::dividirHijo(NodoB* nodo, int idx, NodoB* hijo) {
    NodoB* nuevoNodo = new NodoB(hijo->t, hijo->esHoja);
    nuevoNodo->claves.resize(t - 1);

    for (int i = 0; i < t - 1; i++) {
        nuevoNodo->claves[i] = hijo->claves[i + t];
    }

    if (!hijo->esHoja) {
        for (int i = 0; i < t; i++) {
            nuevoNodo->hijos[i] = hijo->hijos[i + t];
        }
    }

    hijo->claves.resize(t - 1);
    nodo->hijos.insert(nodo->hijos.begin() + idx + 1, nuevoNodo);
    nodo->claves.insert(nodo->claves.begin() + idx, hijo->claves[t - 1]);
}

// Método para insertar una clave en el árbol B
void ArbolB::insertar(int clave) {
    if (raiz == nullptr) {
        raiz = new NodoB(t, true);
        raiz->claves[0] = clave;
    } else {
        if (raiz->claves.size() == 2 * t - 1) {
            NodoB* nuevoNodo = new NodoB(t, false);
            nuevoNodo->hijos[0] = raiz;
            dividirHijo(nuevoNodo, 0, raiz);
            int idx = (nuevoNodo->claves[0] < clave) ? 1 : 0;
            insertarNoLleno(nuevoNodo->hijos[idx], clave);
            raiz = nuevoNodo;
        } else {
            insertarNoLleno(raiz, clave);
        }
    }
}

// Mostrar árbol
void ArbolB::mostrar() {
    if (raiz) mostrarNodo(raiz, 0);
}

void ArbolB::mostrarNodo(NodoB* nodo, int nivel) {
    cout << "Nivel " << nivel << ": ";
    for (int clave : nodo->claves) {
        cout << clave << " ";
    }
    cout << endl;

    if (!nodo->esHoja) {
        for (NodoB* hijo : nodo->hijos) {
            if (hijo) mostrarNodo(hijo, nivel + 1);
        }
    }
}



#endif // ARBOL-B_H_INCLUDED
