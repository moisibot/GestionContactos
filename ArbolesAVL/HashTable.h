#ifndef GESTIONCONTACTOS_HASHTABLE_H
#define GESTIONCONTACTOS_HASHTABLE_H


#include <vector>
#include <memory>
#include <string>
#include "AVLTree.h"
#include "../Grupo.h"

class HashTable {
public:
    HashTable(size_t initialSize = 5);

    void insertContact(const ContactoIndi& contacto, const std::string& campo);
    std::vector<ContactoIndi> findContact(const std::string& campo, const std::string& valor);
    void rehash();

private:
    std::vector<std::unique_ptr<AVLTree>> hashTable;
    size_t hashFunction(const std::string& key) const;
    double loadFactor() const;
};


#endif //GESTIONCONTACTOS_HASHTABLE_H
