#include <iostream>
#include"arbol-b.h"

using namespace std;

int main()
{
    ArbolB arbol(3); // Grado mínimo 3

    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(5);
    arbol.insertar(6);
    arbol.insertar(12);
    arbol.insertar(30);
    arbol.insertar(7);
    arbol.insertar(17);

    cout << "Árbol B:" << endl;
    arbol.mostrar();
    return 0;
}
