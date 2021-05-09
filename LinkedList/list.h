#ifndef LIST_H_
#define LIST_H_
#include "listnode.h"

template<typename Type> class List{

private:
    int _size:
    ListNodePosition<Type> header;
    ListNodePosition<Type> trailer;

protected:
    void init();
    int clear();

public:

    // constructor functions
    List() {init()};
    List(List<Type> const &L);          // copy all list
    List(List<Type> const &L, int n);   // copy list from the n_th node

    // deconstructor
    ~List();


    // only read propriety interface
    Rank size() const {return _size; };
    bool empty() const {return _size <= 0; };

};


template<typename Type> void init()




#endif