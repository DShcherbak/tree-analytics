//
// Created by Ivan Ramyk on 3/21/20.
//

#include "RedBlackTree.hpp"

template<typename TreeItem>
RedBlackTreeNode<TreeItem>::RedBlackTreeNode(const TreeItem &item, RedBlackTreeNode<TreeItem> *left,
        RedBlackTreeNode<TreeItem> *right, RedBlackTreeNode<TreeItem> *parent) :
        BinaryNode<TreeItem>::_value(item),
        _color(BLACK),
        BinaryNode<TreeItem>::_left(left),
        BinaryNode<TreeItem>::_right(right),
        BinaryNode<TreeItem>::_parent(parent)
{}