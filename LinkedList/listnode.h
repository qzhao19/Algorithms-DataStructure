#ifndef LISTNODE_H_ 
#define LISTNODE_H_


using Rank = int;
template<typename Type> struct ListNode;
template<typename Type> using ListNodePosition = ListNode<Type>*;

template<typename Type> struct ListNode{
    Type val;
    ListNodePosition<Type> pred_node;
    ListNodePosition<Type> next_node;

    ListNode(){};

    /*
    ListNode(Type x): value(x), pred_node(nullptr), next_node(nullptr) {};

    ListNode(Type x, ListNode<Type> *pred): 
            value(x), pred_node(pred), next_node(nullptr) {};

    ListNode(Type x, ListNode<Type> *next): 
            value(x), pred_node(nullptr), next_node(next) {};
    */

    // default constructor
    ListNode(Type x, ListNodePosition<Type> pred, ListNodePosition<Type> next): 
            val(x), pred_node(pred), next_node(next) {};
    
    // listNode<Type> insertAsPred(Type const & val)
    // listNode<Type> insertAsNext(Type const & val)

};

#endif