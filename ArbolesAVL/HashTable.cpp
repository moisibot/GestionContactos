/*
#include "HashTable.h"
#include "AVLTree.h"
#include "../Grupo.h"

HashTable::HashTable(size_t initialSize) : hashTable(initialSize) {}

void HashTable::insertContact(const ContactoIndi& contacto, const std::string& campo) {
    size_t index = hashFunction(campo);
    if (!hashTable[index]) {
        hashTable[index] = std::make_unique<AVLTree>();
    }
    hashTable[index]->insert(contacto);
    if (loadFactor() > 0.6) {
        rehash();
    }
}

std::vector<ContactoIndi> HashTable::findContact(const std::string& campo, const std::string& valor) {
    size_t index = hashFunction(campo);
    if (!hashTable[index]) {
        return {};  // Árbol AVL vacío
    }
    return hashTable[index]->find(valor);
}

void HashTable::rehash() {
    std::vector<std::unique_ptr<AVLTree>> newHashTable(hashTable.size() * 2);
    for (auto& tree : hashTable) {
        if (tree) {
            for (const Contacto& contacto : tree->getAllContacts()) {
                size_t index = hashFunction(contacto.getNombreCampo());
                if (!newHashTable[index]) {
                    newHashTable[index] = std::make_unique<AVLTree>();
                }
                newHashTable[index]->insert(contacto);
            }
        }
    }
    hashTable = std::move(newHashTable);
}

size_t HashTable::hashFunction(const std::string& key) const {
    size_t hash = 0;
    for (char c : key) {
        hash = (hash * 31 + static_cast<size_t>(c)) % hashTable.size();
    }
    return hash;
}

double HashTable::loadFactor() const {
    size_t totalElements = 0;
    for (const auto &tree: hashTable) {
        if (tree) {
            totalElements += tree->size();
        }
    }
    return static_cast<double>(totalElements) / hashTable.size();
}
*/