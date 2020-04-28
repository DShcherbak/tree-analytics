//
// Created by darik on 4/26/2020.
//

#include "AVLTree.hpp"

template<typename Item>
void AVLTree<Item>::_rotateLeft(shared_ptr<AVLNode<Item>> node) {
    auto right_sibling = node->_right;
    auto parent = node->_parent;
    if(parent){
        bool is_right_son = (parent->_right == node);
        if (is_right_son) {
            parent->_right = right_sibling;
        } else {
            parent->_left = right_sibling;
        }
    } else {
        _root = right_sibling;
    }

    node->_right = right_sibling->_left;
    right_sibling->_left = node;
    node->_parent = right_sibling;
    right_sibling->_parent = parent;

    node->fixHeight();
    right_sibling->fixHeight();
}

template<typename Item>
void AVLTree<Item>::_rotateRight(shared_ptr<AVLNode<Item>> node) {
    auto left_sibling = node->_left;
    auto parent = node->_parent;

    if(parent){
        bool is_right_son = (parent->_right == node);
        if (is_right_son) {
            parent->_right = left_sibling;
        } else {
            parent->_left = left_sibling;
        }
    } else {
        _root = left_sibling;
    }

    node->_left = left_sibling->_right;
    left_sibling->_right = node;
    node->_parent = left_sibling;
    left_sibling->_parent = parent;

    node->fixHeight();
    left_sibling->fixHeight();
}

template<typename Item>
void AVLTree<Item>::_bigRotateLeft(shared_ptr<AVLNode<Item>> node) {
    _rotateRight(node->_right);
    _rotateLeft(node);
}

template<typename Item>
void AVLTree<Item>::_bigRotateRight(shared_ptr<AVLNode<Item>> node) {
    _rotateLeft(node->_left);
    _rotateRight(node);
}

template <typename Item>
shared_ptr<AVLNode<Item>> AVLTree<Item>::search(Item key) {
    auto node = _root;
    while (node){
        if (node->_key == key) return node;
        else if (key < node->_key){
            node = node->_left;
        } else {
            node = node->_right;
        }
    }
    return nullptr;
}

template<typename Item>
void AVLTree<Item>::insert(Item key) {
    if (_root == nullptr) {
        _root = make_shared<AVLNode<Item>>(key, nullptr, nullptr, nullptr);
        return;
    }
    shared_ptr<AVLNode<Item>> node_for_insert = shared_ptr<AVLNode<Item>>(this->_root);
    for (;;) {
        if (key < node_for_insert->_key) {
            if (node_for_insert->_left) {
                node_for_insert = node_for_insert->_left;
            } else {
                node_for_insert->_left = make_shared<AVLNode<Item>>(key, nullptr, nullptr, node_for_insert);
                break;
            }
        } else {
            if (node_for_insert->_right) {
                node_for_insert = node_for_insert->_right;
            } else {
                node_for_insert->_right = make_shared<AVLNode<Item>>(key, nullptr, nullptr, node_for_insert);
                break;
            }
        }
    }

    while (node_for_insert) {
        node_for_insert->fixHeight();
        if (abs(node_for_insert->diff()) == 1) {
            node_for_insert = node_for_insert->_parent;
        } else if (node_for_insert->diff() == -2) {
            std::cout << "WTF" << std::endl;
            if (node_for_insert->_right->diff() == -1 || node_for_insert->_right->diff() == 0) {
                _rotateLeft(node_for_insert);
                return;
            } else if (node_for_insert->_right->diff() == 1) {
                _bigRotateLeft(node_for_insert);
            }
        } else if (node_for_insert->diff() == 2) {
            if (node_for_insert->_left->diff() == 1 || node_for_insert->_left->diff() == 0) {
                _rotateRight(node_for_insert);
                return;
            } else if (node_for_insert->_left->diff() == 1) {
                _bigRotateRight(node_for_insert);
            }
        } else if (node_for_insert->diff() == 0)
            return;
        else {
            node_for_insert = node_for_insert->_parent;
        }
    }
}

