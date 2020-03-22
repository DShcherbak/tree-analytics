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
class RedBlackTreeNode : BinaryNode<TreeItem> {
private:
    color _color;
public:
    explicit RedBlackTreeNode(
            const TreeItem& item,
            RedBlackTreeNode<TreeItem> * left = nullptr,
            RedBlackTreeNode<TreeItem> * right = nullptr,
            RedBlackTreeNode<TreeItem> * parent = nullptr);
    friend class RedBlackTree<TreeItem>;
};

template <typename TreeItem>
class RedBlackTree : BinaryTree<TreeItem>{
private:
    RedBlackTreeNode <TreeItem> * _root;
    void _leftRotate(RedBlackTreeNode<TreeItem> * node){

    }

    void _rightRotate(RedBlackTreeNode<TreeItem> * node){

    }

    void _fixInsertion(RedBlackTreeNode<TreeItem> * node);

public:
    RedBlackTree(){
        _root = nullptr;
    }
    void insert(TreeItem item) override;
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
        if (item < previous_node->_item){
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
    while (node->_parent != nullptr && node->_parent._color == RED){
        if (node->_parent == node->_parent->_parent->_left){
            if (node->_parent->_parent->_right != nullptr){
                if (node->_parent._parent._right._color == RED){
                    node->_parent._color = BLACK;
                    node->_parent._parent._right._color == BLACK;
                    node->_parent._parent._color = RED;
                    node = node->_parent._parent;
                }
            }
            else {
                if (node->_parent._right == node){
                    node = node->_parent;//tuta ostanovilsia
                    _leftRotate(node);
                }
                node->_parent._color = BLACK;
                node->_parent->_parent._color = RED;
                _rightRotate(node->_parent->_parent);
            }
        }
        else {
            if (node->_parent->_parent->_left != nullptr){
                if (node->_parent._parent._left._color == RED){
                    node->_parent._color = BLACK;
                    node->_parent._parent._left._color == BLACK;
                    node->_parent._parent._color = RED;
                    node = node->_parent._parent;
                }
            }
            else {
                if (node->_parent._left == node){
                    node = node->_parent;//tuta ostanovilsia
                    _rightRotate(node);
                }
                node->_parent._color = BLACK;
                node->_parent->_parent._color = RED;
                _leftRotate(node->_parent->_parent);
            }
        }
    }
    BinaryTree<TreeItem>:: _root->_color = BLACK;
}


#endif //ALGORITHMS_REDBLACKTREE_HPP
