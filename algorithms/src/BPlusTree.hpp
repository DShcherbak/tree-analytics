//
// Created by darik on 4/10/2020.
//

#include <vector>
#include <algorithm>
#include <memory>

using std::shared_ptr;
using std::vector;

#ifndef ALGORITHMS_BPLUS_TREE_HPP
#define ALGORITHMS_BPLUS_TREE_HPP

template<typename T>
class Node {
public:
    bool _leaf{false};
    int _key_num{0};
    std::vector<int> _key;
    shared_ptr<Node<T> > _parent;
    shared_ptr<Node<T> > _left_sibling;
    shared_ptr<Node<T> > _right_sibling;
    vector<shared_ptr<Node<T> > > _children;
    vector<shared_ptr<T> > _info;
};

template<typename T>
class BPlusTree {
public:
    explicit BPlusTree(int t) : _t{t} {
        _root = std::make_shared<Node<T> >();
        _root->_leaf = true;
    }

    std::shared_ptr<T> search(int key);

    bool insert(int key, shared_ptr<T> value);

    bool remove(int key);

private:

    void _removeInNode(shared_ptr<Node<T> > node, int key);

    void _split(shared_ptr<Node<T> > node);

    shared_ptr<Node<T> > _findLeaf(int key);

    int _getMin(shared_ptr<Node<T> > node);

    void _update(shared_ptr<Node<T> > node);

    shared_ptr<Node<T> > _root;
    int _t;
};

#include "BPlusTree.tpp"

#endif //ALGORITHMS_BPLUS_TREE_HPP
