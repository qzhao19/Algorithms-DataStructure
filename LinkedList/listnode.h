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


    // default constructor
    ListNode(Type x, ListNodePosition<Type> prev, ListNodePosition<Type> next): 
            val(x), prev(prev), next(next) {};
    
    ListNodePosition<Type> insertAsPrev(Type const &x);
    ListNodePosition<Type> insertAsNext(Type const &x);

};

#endif