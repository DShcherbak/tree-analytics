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
class RedBlackTreeNode : BinaryNode<TreeItem> {
private:
    color _color;
public:
    explicit RedBlackTreeNode(
            const TreeItem& item,
            RedBlackTreeNode<TreeItem> * left = nullptr,
            RedBlackTreeNode<TreeItem> * right = nullptr,
            RedBlackTreeNode<TreeItem> * parent = nullptr);
    template <TreeItem> friend class RedBlackTree;
};

template <typename TreeItem>
class RedBlackTree : BinaryTree<TreeItem>{
private:
    RedBlackTree(): BinaryTree<TreeItem>::_root(nullptr) {}

    void fixInsertion(RedBlackTreeNode<TreeItem> * node){
        while (node->_parent._color == RED){
            if (node->_parent._item < node->_parent._parent._item){
                if (node->_parent._parent._right != nullptr){
                    if (node->_parent._parent._right._color == RED){
                        node->_parent._color = BLACK;
                        node->_parent._parent._right._color == BLACK;
                        node->_parent._parent = RED;
                        node = node->_parent._parent;
                    }
                }
                else {
                    if (node->_parent._right == node){
                        node = node->_parent;//tuta ostanovilsia
                    }
                }
            }
        }
    }
    void insert(TreeItem item) override;
};

template<typename TreeItem>
void RedBlackTree<TreeItem>::insert(TreeItem item) {
    if (BinaryTree<TreeItem>::_root == nullptr){
        BinaryTree<TreeItem>::_root = new RedBlackTreeNode<TreeItem>(item);
        BinaryTree<TreeItem>::_root->_color = BLACK;
    }
    else {
        RedBlackTreeNode<TreeItem> *current_node = BinaryTree<TreeItem>::_root;
        RedBlackTreeNode<TreeItem> *previous_node = nullptr;
        while (current_node != nullptr) {
            if (item < current_node->_item) {
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
        fixInsertion(current_node);
    }
}



#endif //ALGORITHMS_REDBLACKTREE_HPP
