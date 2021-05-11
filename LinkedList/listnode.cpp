#include <iostream>
#include "listnode.h"

template <typename Type>
ListNodePosition<Type> ListNode<Type>::insertAsPrev(Type const &x) {
    ListNodePosition<Type> node = new ListNode(x, prev, this);

    prev -> next = node;
    prev = node;

    return node;
};


template <typename Type>
ListNodePosition<Type> ListNode<Type>::insertAsNext(Type const &x) {
    ListNodePosition<Type> node = new ListNode(x, this, next);

    next -> prev = node;
    next = node;

    return node;
}