#ifndef LISTNODE_H_ 
#define LISTNODE_H_


using Rank = int;
template<typename Type> struct ListNode;
template<typename Type> using ListNodePosition = ListNode<Type>*;

template<typename Type> struct ListNode{
    Type val;
    ListNodePosition<Type> prev;
    ListNodePosition<Type> next;

    ListNode(){};

    /*
    ListNode(Type x): value(x), pred_node(nullptr), next_node(nullptr) {};

    ListNode(Type x, ListNode<Type> *pred): 
            value(x), pred_node(pred), next_node(nullptr) {};

    ListNode(Type x, ListNode<Type> *next): 
            value(x), pred_node(nullptr), next_node(next) {};
    */

    // default constructor
    ListNode(Type x, ListNodePosition<Type> prev, ListNodePosition<Type> next): 
            val(x), prev(prev), next(next) {};
    
    ListNodePosition<Type> insertAsPrev(Type const &x);
    ListNodePosition<Type> insertAsNext(Type const &x);

};

#endif