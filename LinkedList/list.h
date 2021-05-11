#ifndef LIST_H_
#define LIST_H_
#include "listnode.h"

template<typename Type> class List{

private:
    int _size;
    ListNodePosition<Type> header;
    ListNodePosition<Type> trailer;

protected:
    void init();
    int clear();
    void copyNodes(ListNodePosition<Type> node, int n);


public:

    // constructor functions
    List();
    List(List<Type> const &L);          // copy all list
    List(ListNodePosition<Type> node, int n);   // copy list from the n_th node

    // deconstructor
    ~List();


    // only read propriety interface
    int size() const {
        return _size; 
    }

    bool empty() const {
        return _size <= 0; 
    }

    ListNodePosition<Type> first() {
        return header -> next;
    }

    ListNodePosition<Type> last() {
        return trailer -> prev;
    }

    bool valid(ListNodePosition<Type> node) {
        return node && (header != node) && (trailer != node);
    }


    // writable interface
    ListNodePosition<Type> insertAsFirst(Type const &x);
    ListNodePosition<Type> insertAsLast(Type const &x);

    Type remove(ListNodePosition<Type> node);




};



#endif;