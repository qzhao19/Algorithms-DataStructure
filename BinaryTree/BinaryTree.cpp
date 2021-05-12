#include <iostream>
#include "BinaryTree.h"

template <typename T>
TreeNode<T>* BinaryTree<T>::copy(const TreeNode<T> *node) {
    if (node == nullptr) {
        return nullptr;
    }

    return new TreeNode(node-> val, copy(node -> left), copy(node -> right));

}


template <typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree) {
    if (tree.root == nullptr) {
        root = nullptr;
    }

    root = copy(tree.root);
}

template <typename T>
BinaryTree<T>::BinaryTree(const T &x) {
    root = TreeNode(x);
}


