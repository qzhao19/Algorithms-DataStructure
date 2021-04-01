# ifndef NODE_H
# define NODE_H

template <class T>
class Node{

public:
    Node<T> *prev;
    Node<T> *next;
    T data;
};

# endif //NODE_H

