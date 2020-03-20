#ifndef ALGORITHMS_LIBRARY_H
#define ALGORITHMS_LIBRARY_H

template <typename T>
class Node
{
public:
    T _value;
    Node<T>* _left = nullptr;
    Node<T>* _right = nullptr;
    Node<T>* _parent = nullptr;
    Node<T>* _child = nullptr;
};

template <typename T>
class Tree
{
public:
    Node<T>* _root;
    virtual void Insert(T value);
    virtual void Remove(Node<T>*);
    virtual Node<T>* Search(T value);
};

#endif //ALGORITHMS_LIBRARY_H
