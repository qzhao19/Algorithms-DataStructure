#include <iostream>
#include "listnode.h"

template <typename Type>
ListNodePosition<Type> ListNode<Type>::insertAsPred(Type const &x) {
    ListNodePosition<Type> node = new ListNode(x, pred, this);

    pred -> next = node;
    pred = node;

    return node;
};


template <typename Type>
ListNodePosition<Type> ListNode<Type>::insertAsNext(Type const &x) {
    ListNodePosition<Type> node = new ListNode(x, this, next);

    next -> pred = node;
    next = node;

    return node;
}