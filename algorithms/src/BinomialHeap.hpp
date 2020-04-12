//
// Created by darik on 4/12/2020.
//

#ifndef ALGORITHMS_BINOMIALHEAP_HPP
#define ALGORITHMS_BINOMIALHEAP_HPP

#include <iostream>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::make_shared;

template<typename T>
class BinomialNode {
public:
    BinomialNode() = default;

    BinomialNode(T value) : _key{value} {}

    T _key;
    shared_ptr<BinomialNode<T>> _child;
    shared_ptr<BinomialNode<T>> _parent;
    shared_ptr<BinomialNode<T>> _sibling; // for roots in Binomial heap sibling is the next root in the list
    unsigned _degree = 0; // number of children
};

template<typename T>
class BinomialHeap {
public:
    BinomialHeap() = default;

    shared_ptr<BinomialNode<T>> _head;

    void insert(T value);

    shared_ptr<BinomialNode<T>> getMinimum();

    void decreaseKey(shared_ptr<BinomialNode<T>> node, const T &k);

    shared_ptr<BinomialNode<T>> extractMin(); // return pointer on the node with min key

    void remove(shared_ptr<BinomialNode<T>> node);

private:
    void sort(); // sort by degrees of roots in increasing order

    void merge();
};

#include "BinomialHeap.tpp"

#endif //ALGORITHMS_BINOMIALHEAP_HPP
