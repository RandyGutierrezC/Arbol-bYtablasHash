#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <vector>
#include <list>
#include <string>
#include <functional>
#include <iostream>
using namespace std;

// Clase HashTable
class HashTable {
private:
    size_t bucketCount;
    vector<list<pair<string, int>>> table;

    // Función hash
    size_t hashFunction(const string& key)  {
        return hash<string>()(key) % bucketCount;
    }

public:
    HashTable(size_t size){
         this->bucketCount = size;
         this->table.resize(size);
    }

    // Insertar clave-valor
    void insert(const string& key, int value) {
        size_t index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    // Buscar un valor por clave
    bool search(const string& key, int& value) {
        size_t index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    // Eliminar un valor por clave
    bool remove(const string& key) {
        size_t index = hashFunction(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return true;
            }
        }
        return false;
    }

    // Imprimir la tabla hash
    void print() const {
        for (size_t i = 0; i < table.size(); ++i) {
            cout << "Bucket " << i << ":";
            for (const auto& pair : table[i]) {
                cout << " (" << pair.first << ", " << pair.second << ")";
            }
            cout << "\n";
        }
    }
};


#endif // HASH_H_INCLUDED
