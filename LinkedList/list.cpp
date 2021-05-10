#include <iostream>
#include "list.h"

template<typename Type>
void List<Type>::init() {
    header = new ListNode<Type>;
    trailer = new ListNode<Type>;

    header -> next = trailer;
    header -> succ = nullptr;

    trailer -> next = nullptr;
    trailer -> succ = header;

    _size = 0;
};

template<typename Type>
void List<Type>::copyNodes(ListNodePosition<Type> node, int n) {
    init();

    while (n--) {
        insertAsLast(node -> val);
        node = node -> next;
    }
}









