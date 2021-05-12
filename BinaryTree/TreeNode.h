#ifndef TREENODE_H_
#define TREENODE_H_


template<typename T> 
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(T x): val(x), left(nullptr), right(nullptr) {};
    TreeNode(TreeNode *node): val(node-> val), left(node -> left), right(node -> right) {};
    TreeNode(T x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {};

};


#endif