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
}

template<typename Type>
int List<Type>::clear() {
    int old_size = _size;

    while (_size > 0) {
        remove(header -> next);
    }

    return old_size;
}


template<typename Type>
void List<Type>::copyNodes(ListNodePosition<Type> node, int n) {
    init();

    while (n--) {
        insertAsLast(node -> val);
        node = node -> next;
    }
}
//***********************************************************************************//

template<typename Type>
List<Type>::List() {
    init();
}


template<typename Type>
List<Type>::List(List<Type> const &L) {
    copyNodes(L.first(), L._size());
}

template<typename Type>
List<Type>::List(ListNodePosition<Type> node, int n) {
    copyNodes(node, n);
}

//***********************************************************************************//

template<typename Type>
List<Type>::~List() {
    clear();
    delete header;
    delete trailer;
}

//************************************************************************************//
template<typename Type>
ListNodePosition<Type> List<Type>::insertAsFirst(Type const &x) {
    _size++;
    return header -> insertAsPrev(x);
}

template<typename Type>
ListNodePosition<Type> List<Type>::insertAsLast(Type const & x) {
    _size++;
    return trailer -> insertAsNext(x);
}


template<typename Type>
Type List<Type>::remove(ListNodePosition<Type> node) {
    Type x = node -> val;
    node -> prev -> next = node -> next;
    node -> next -> prev = node -> prev;
    delete node;
    _size--;

    return x;
}










