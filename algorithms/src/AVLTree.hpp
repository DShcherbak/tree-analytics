//
// Created by darik on 4/26/2020.
//

#ifndef ALGORITHMS_AVLTREE_HPP
#define ALGORITHMS_AVLTREE_HPP

#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;

template<typename Item>
class AVLNode {
public:
    Item _key;
    shared_ptr<AVLNode> _left;
    shared_ptr<AVLNode> _right;
    shared_ptr<AVLNode> _parent;
    int _height{1};

    AVLNode<Item>(Item key, shared_ptr<AVLNode> left = nullptr, shared_ptr<AVLNode> right = nullptr,
                  shared_ptr<AVLNode> parent = nullptr)
            : _key{key}, _left{left}, _right{right}, _parent{parent} {}

    void fixHeight() {
        int left_height{0}, right_height{0};
        if (_left) left_height = _left->_height;
        if (_right) right_height = _right->_height;
        _height = std::max(left_height, right_height) + 1;
    }

    int diff() {
        int left_height{0}, right_height{0};
        if (_left) left_height = _left->_height;
        if (_right) right_height = _right->_height;
        return left_height - right_height;
    }
};

template<typename Item>
class AVLTree {
public:
    shared_ptr<AVLNode<Item>> search(Item);

    void insert(Item);

    void remove(Item);

    void print() {
        print(_root);
        std::cout << std::endl;
    };
private:
    shared_ptr<AVLNode<Item>> _root;

    void _rotateLeft(shared_ptr<AVLNode<Item>>);

    void _bigRotateLeft(shared_ptr<AVLNode<Item>>);

    void _rotateRight(shared_ptr<AVLNode<Item>>);

    void _bigRotateRight(shared_ptr<AVLNode<Item>>);

    void print(shared_ptr<AVLNode<Item>> node) {
        if (node == nullptr)
            return;
        std::cout << node->_key;
        if (node->_left || node->_right) std::cout << "(";
        print(node->_left);
        if (node->_left && node->_right) std::cout << ",";
        print(node->_right);
        if (node->_left || node->_right) std::cout << ")";
    }
};

#include "AVLTree.tpp"

#endif //ALGORITHMS_AVLTREE_HPP
