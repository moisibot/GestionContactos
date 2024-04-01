/*
#include "AVLTree.h"
#include <algorithm>
#include "../Grupo.h"
#include "sstream"
#include <cctype>
#include "iostream"
#include <sstream>
#include "filesystem"
#include "vector"
#include "fstream"
#include "../IngresarContacto/Contacto.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {

}

int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(Node* node) {
    return height(node->right) - height(node->left);
}

void AVLTree::fixHeight(Node* node) {
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

AVLTree::Node* AVLTree::rightRotate(Node* node) {
    Node* leftNode = node->left;
    node->left = leftNode->right;
    leftNode->right = node;
    fixHeight(node);
    fixHeight(leftNode);
    return leftNode;
}

AVLTree::Node* AVLTree::leftRotate(Node* node) {
    Node* rightNode = node->right;
    node->right = rightNode->left;
    rightNode->left = node;
    fixHeight(node);
    fixHeight(rightNode);
    return rightNode;
}

AVLTree::Node* AVLTree::insert(Node* node, const Contacto& data) {
    if (!node) {
        return new Node(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        // El dato ya existe, puedes manejar este caso según tus necesidades
        return node;
    }

    fixHeight(node);

    int balance = balanceFactor(node);

    if (balance > 1 && data > node->right->data) {
        return leftRotate(node);
    }

    if (balance < -1 && data < node->left->data) {
        return rightRotate(node);
    }

    if (balance > 1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    if (balance < -1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    return node;
}

void AVLTree::insert(const Contacto& data) {
    root = insert(root, data);
}

AVLTree::Node* AVLTree::remove(Node* node, const std::string& campo, const std::string& valor) {
    // Implementar la eliminación de un nodo en el árbol AVL
    return node;
}

void AVLTree::remove(const std::string& campo, const std::string& valor) {
    root = remove(root, campo, valor);
}

std::vector<Contacto> AVLTree::find(Node* node, const std::string& valor) const {
    std::vector<Contacto> result;
    if (!node) {
        return result;
    }

    if (node->data.getCampo(campo) == valor) {
        result.push_back(node->data);
    }

    auto leftResult = find(node->left, valor);
    result.insert(result.end(), leftResult.begin(), leftResult.end());

    auto rightResult = find(node->right, valor);
    result.insert(result.end(), rightResult.begin(), rightResult.end());

    return result;
}

std::vector<Contacto> AVLTree::find(const std::string& valor) const {
    return find(root, valor);
}

std::vector<Contacto> AVLTree::getAllContacts() const {
    std::vector<Contacto> result;
    // Implementar la función para obtener todos los contactos en orden
    return result;
}

size_t AVLTree::size() const {
    // Implementar la función para obtener el tamaño del árbol
    return 0;
}

*/