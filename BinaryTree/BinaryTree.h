#ifndef BINARYTREE_H_
#define BINARYTREE_H

#include "TreeNode.h"


template<typename T>
class BinaryTree {
private:
    TreeNode<T> *root;

protected:
    TreeNode<T> * copy(TreeNode<T> *node);
    void clear(TreeNode<T> *node);

    void insert(TreeNode<T> *node, const T &x);
    void remove(TreeNode<T> *node, const T &x);




public:
    BinaryTree();
    BinaryTree(const BinaryTree<T> &tree);
    BinaryTree(const T &x);

    ~BinaryTree() {};

    void insert(const T &x);
    void remove(const T &x);







};







#endif