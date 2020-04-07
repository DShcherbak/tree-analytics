//
// Created by Ivan Ramyk on 3/21/20.
//

#ifndef ALGORITHMS_REDBLACKTREE_HPP
#define ALGORITHMS_REDBLACKTREE_HPP

#include "BinaryTree.hpp"



enum color {
    RED, BLACK
};
template <typename TreeItem>
class RedBlackTree;

template <typename TreeItem>
class RedBlackTreeNode{
private:
    TreeItem _value;
    RedBlackTreeNode<TreeItem> * _left;
    RedBlackTreeNode<TreeItem> * _right;
    RedBlackTreeNode<TreeItem> * _parent;
    color _color;
public:
    RedBlackTreeNode<TreeItem> (
            TreeItem item,
            RedBlackTreeNode<TreeItem> * left = nullptr,
            RedBlackTreeNode<TreeItem> * right = nullptr,
            RedBlackTreeNode<TreeItem> * parent = nullptr);

    TreeItem value();

    friend class RedBlackTree<TreeItem>;
};

template <typename TreeItem>
class RedBlackTree {
private:
    RedBlackTreeNode <TreeItem> * _root;
    void _leftRotate(RedBlackTreeNode<TreeItem> * node){
        RedBlackTreeNode<TreeItem> * y = node->_right;
        RedBlackTreeNode<TreeItem> * x = y->_left;
        y->_parent = node->_parent;
        if (node->_parent == nullptr){
            _root = y;
        }
        else if (node == node->_parent->_left){
            node->_parent->_left = y;
        }
        else node->_parent->_right = y;
        node->_parent = y;
        y->_left = node;
        node->_right = x;
        if (x != nullptr)
            x->_parent = node;
    }

    void _rightRotate(RedBlackTreeNode<TreeItem> * node){
        RedBlackTreeNode<TreeItem> * y = node->_left;
        RedBlackTreeNode<TreeItem> * x = y->_right;
        y->_parent = node->_parent;
        if (node->_parent == nullptr){
            _root = y;
        }
        else if (node == node->_parent->_left){
            node->_parent->_left = y;
        }
        else node->_parent->_right = y;
        node->_parent = y;
        y->_right = node;
        node->_left = x;
        if (x != nullptr)
            x->_parent = node;
    }

    void _fixInsertion(RedBlackTreeNode<TreeItem> * node);

public:
    RedBlackTree(){
        _root = nullptr;
    }
    void insert(TreeItem item);

    RedBlackTreeNode <TreeItem> * search(TreeItem item);
};

template<typename TreeItem>
void RedBlackTree<TreeItem>::insert(TreeItem item) {
    if (_root == nullptr){
        _root = new RedBlackTreeNode<TreeItem>(item);
        _root->_color = BLACK;
    }
    else {
        RedBlackTreeNode<TreeItem> *current_node = _root;
        RedBlackTreeNode<TreeItem> *previous_node = nullptr;
        while (current_node != nullptr) {
            if (item < current_node->_value) {
                previous_node = current_node;
                current_node = current_node->_left;
            } else {
                previous_node = current_node;
                current_node = current_node->_right;
            }
        }
        current_node = new RedBlackTreeNode<TreeItem>(item);
        current_node->_parent = previous_node;
        if (item < previous_node->_value){
            previous_node->_left = current_node;
        }
        else {
            previous_node->_right = current_node;
        }
        _fixInsertion(current_node);
    }
}

template<typename TreeItem>
void RedBlackTree<TreeItem>::_fixInsertion(RedBlackTreeNode<TreeItem> *node) {
    while (node->_parent != nullptr && node->_parent->_color == RED){
        if (node->_parent == node->_parent->_parent->_left){
            if (node->_parent->_parent->_right != nullptr){
                if (node->_parent->_parent->_right->_color == RED){
                    node->_parent->_color = BLACK;
                    node->_parent->_parent->_right->_color == BLACK;
                    node->_parent->_parent->_color = RED;
                    node = node->_parent->_parent;
                }
            }
            else {
                if (node->_parent->_right == node){
                    node = node->_parent;//tuta ostanovilsia
                    _leftRotate(node);
                }
                node->_parent->_color = BLACK;
                node->_parent->_parent->_color = RED;
                _rightRotate(node->_parent->_parent);
            }
        }
        else {
            if (node->_parent->_parent->_left != nullptr){
                if (node->_parent->_parent->_left->_color == RED){
                    node->_parent->_color = BLACK;
                    node->_parent->_parent->_left->_color == BLACK;
                    node->_parent->_parent->_color = RED;
                    node = node->_parent->_parent;
                }
            }
            else {
                if (node->_parent->_left == node){
                    node = node->_parent;//tuta ostanovilsia
                    _rightRotate(node);
                }
                node->_parent->_color = BLACK;
                node->_parent->_parent->_color = RED;
                _leftRotate(node->_parent->_parent);
            }
        }
    }
    _root->_color = BLACK;
}

template<typename TreeItem>
RedBlackTreeNode<TreeItem> *RedBlackTree<TreeItem>::search(TreeItem item) {
    RedBlackTreeNode <TreeItem> * node  = _root;
    while (node != nullptr && node->_value != item){
        if (item < node->_value)
            node = node->_left;
        else
            node = node->_right;
    }
    return node;
}


template<typename TreeItem>
RedBlackTreeNode<TreeItem>::RedBlackTreeNode(TreeItem item, RedBlackTreeNode<TreeItem> *left,
                                             RedBlackTreeNode<TreeItem> *right, RedBlackTreeNode<TreeItem> *parent) :
        _value(item),
        _color(RED),
        _left(left),
        _right(right),
        _parent(parent)
{}

template<typename TreeItem>
TreeItem RedBlackTreeNode<TreeItem>::value() {
    return _value;
}


#endif //ALGORITHMS_REDBLACKTREE_HPP
