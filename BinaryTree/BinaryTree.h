#ifndef BINARYTREE_H_
#define BINARYTREE_H

#include "TreeNode.h"


template<typename T>
class BinaryTree {
private:
    TreeNode *root;

protected:
    TreeNode<T> * copy(const TreeNode<T> *node);
    void clear();

public:
    BinaryTree();
    BinaryTree(const BinaryTree<T> &tree);
    BinaryTree(const T &x);



};







#endif