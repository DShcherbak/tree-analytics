#ifndef ALGORITHMS_BINARYTREE_HPP
#define ALGORITHMS_BINARYTREE_HPP

template <typename T>
class BinaryNode
{
public:
    T _value;
    BinaryNode<T>* _left = nullptr;
    BinaryNode<T>* _right = nullptr;
    BinaryNode<T>* _parent = nullptr;
};

template <typename T>
class BinaryTree
{
public:
    virtual void insert(T value);
    virtual void remove(T value);
    virtual BinaryNode<T>* search(T value);
};

#endif //ALGORITHMS_BINARYTREE_HPP
