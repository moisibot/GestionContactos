#ifndef GESTIONCONTACTOS_AVL_H
#define GESTIONCONTACTOS_AVL_H
#include <vector>
#include "../Grupo.h"

class AVLTree {
private:
    struct Node {
        ContactoIndi data;
        Node* left;
        Node* right;
        int height;

        Node(const ContactoIndi& data)
                : data(data), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* node);
    int balanceFactor(Node* node);
    void fixHeight(Node* node);
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
    Node* insert(Node* node, const ContactoIndi& data);
    Node* remove(Node* node, const std::string& campo, const std::string& valor);
    std::vector<ContactoIndi> find(Node* node, const std::string& valor) const;

public:
    AVLTree();
    ~AVLTree();

    void insert(const ContactoIndi& data);
    void remove(const std::string& campo, const std::string& valor);
    std::vector<ContactoIndi> find(const std::string& valor) const;
    std::vector<ContactoIndi> getAllContacts() const;
    size_t size() const;
};



#endif //GESTIONCONTACTOS_AVL_H
