#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "TreeNode.h"


template<typename T> class BinaryTree {
private:
    TreeNode<T> *root;

protected:
    TreeNode<T> *copy(TreeNode<T> *node);
    void clear(TreeNode<T> *node);

    void insert(TreeNode<T> *node, const T &x);
    void remove(TreeNode<T> *node, const T &x);
    TreeNode<T> *search(TreeNode<T> *node, const T &x);

    void inorderTraversal(TreeNode<T> *node);
    void postorderTraversal(TreeNode<T> *node);
    void preorderTraversal(TreeNode<T> *node);

public:
    BinaryTree();
    BinaryTree(const BinaryTree<T> &tree);
    BinaryTree(const T &x);

    ~BinaryTree() {};

    void insert(const T &x);
    void remove(const T &x);
    TreeNode<T> search(const T &x);

    void inorderTraversal();
    void postorderTraversal();
    void preorderTraversal();


};




#endif