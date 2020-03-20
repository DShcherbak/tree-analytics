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
    BinaryNode<T>* _root;
    virtual void Insert(T value);
    virtual void Remove(T value);
    virtual BinaryNode<T>* Search(T value);
};

#endif //ALGORITHMS_BINARYTREE_HPP
