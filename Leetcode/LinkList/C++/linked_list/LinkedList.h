#ifdef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>



template <class T> 
class LinkedList{

private:
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    List(); //default constructor
    List(const List &L); // copy constructor, here is deepcopy type

};


////////////////////////////////////////////////////////////////////////////////////////////
//default constructor
template<typename T>
List<T>::List(){
    //create a head and tail node
    head = new Node<T>;
    tail = new Node<T>;

    // head points to tail 
    head -> next = tail;
    head -> prev = nullptr;
    tail -> next = nullptr;
    tail -> prev = head;
    length = 0;
}

template<typename T>
List<T>::List(const List &L){
    //create a head and tail node
    head = new Node<T>;
    tail = new Node<T>;

    head -> prev = nullptr;
    head -> next = tail;
    tail -> prev = head;
    
    

}




#endif