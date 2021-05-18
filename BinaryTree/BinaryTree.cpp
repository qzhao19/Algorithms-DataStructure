#include <iostream>
#include "BinaryTree.h"

template <typename T>
TreeNode<T>* BinaryTree<T>::copy(TreeNode<T> *node) {
    if (node == nullptr) {
        return nullptr;
    }

    return new TreeNode(node-> val, copy(node -> left), copy(node -> right));

}

template <typename T>
void BinaryTree<T>::clear(TreeNode<T> *node) {
    if (node != nullptr) {
        clear(node -> left);
        clear(node -> right);
        delete node;
    }

    node = nullptr;
}



template <typename T>
void BinaryTree<T>::insert(TreeNode<T> *node, const T &x) {
    if (x < node -> val) {
        if (node -> left != nullptr) {
            insert(node -> left, x);
        }
        else {
            node -> left = new TreeNode<T>;
            node -> left -> val = x;
            node -> left -> left = nullptr;
            node -> left -> right = nullptr;
        }
    }
    else if (x >= node -> val) {
        if (node -> right != nullptr) {
            insert(node -> right, x);
        }
        else {
            node -> right = new TreeNode<T>;
            node -> right -> val = x;
            node -> right -> left = nullptr;
            node -> right -> right = nullptr;
        }
    }
    
}

template<typename T>
void BinaryTree<T>::remove(TreeNode<T> *node, const T &x) {
    if (node == nullptr) {
        return ;
    }
    else {
        if (x < node -> val) {
            remove(node -> left, x);
        }
        else if (x > node -> val) {
            remove(node -> right, x);
        } 
        else if (node -> left != nullptr && node -> right != nullptr) {
            node -> val = findMin(node -> right) -> val;
            remove(node -> right, node -> val);
        }
        else {
            TreeNode<T> *old_node = node;
            node = (node -> left != nullptr) ? node -> left ? node -> right;
            delete old_node;
        }
    }

}


template<typename T>
TreeNode<T>* BinaryTree<T>::findMin(TreeNode<T> *node) const {
    if (node != nullptr) {
        while (node -> left != nullptr) {
            node = node -> left;
        }
    }

    return node;
}

template<typename T>
TreeNode<T>* BinaryTree<T>::findMax(TreeNode<T> *node) const {
    if (node != nullptr) {
        while (node -> right != nullptr) {
            node = node -> right;
        }
    }

    return node;
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

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
}


template <typename T>
void BinaryTree<T>::insert(const T &x) {
    if (root != nullptr) {
        insert(root, x);
    } 
    else {
        root = new TreeNode<T>;
        root -> val = x;
        root -> left = nullptr;
        root -> right = nullptr;
    } 

}

template <typename T>
void BinaryTree<T>::remove(const T &x) {
    remove(root, x);
}




