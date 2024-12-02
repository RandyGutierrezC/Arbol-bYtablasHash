#include <iostream>
#include"Hash.h"
using namespace std;

int main()
{
     HashTable hashTable(10); // Crear tabla hash con 10 buckets

    // Insertar elementos
    hashTable.insert("Alice", 25);
    hashTable.insert("Bob", 30);
    hashTable.insert("Charlie", 35);

    // Buscar un elemento
    int value;
    if (hashTable.search("Bob", value)) {
        cout << "Bob tiene el valor: " << value << "\n";
    } else {
        cout << "Bob no se encuentra en la tabla.\n";
    }

    // Eliminar un elemento
    if (hashTable.remove("Alice")) {
        cout << "Alice fue eliminada.\n";
    } else {
        cout << "Alice no se encuentra en la tabla.\n";
    }

    // Imprimir la tabla hash
    hashTable.print();
    return 0;
}
