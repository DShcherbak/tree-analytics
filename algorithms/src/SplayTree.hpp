//
// Created by ivan on 08.04.20.
//

#ifndef ALGORITHMS_SPLAYTREE_HPP
#define ALGORITHMS_SPLAYTREE_HPP

#include <vector>

template <typename TreeItem>
class SplayTree;

template <typename TreeItem>
class SplayTreeNode{
private:
    TreeItem _value;
    SplayTreeNode<TreeItem> * _left;
    SplayTreeNode<TreeItem> * _right;
    SplayTreeNode<TreeItem> * _parent;
public:
    explicit SplayTreeNode<TreeItem> (
            TreeItem item,
            SplayTreeNode<TreeItem> * left = nullptr,
            SplayTreeNode<TreeItem> * right = nullptr,
            SplayTreeNode<TreeItem> * parent = nullptr);

    TreeItem value();

    friend class SplayTree<TreeItem>;
};

template <typename TreeItem>
class SplayTree {
private:
    SplayTreeNode <TreeItem> * _root;

    void _print(SplayTreeNode<TreeItem> * node, std::vector<std::pair<TreeItem, TreeItem>> &events);

    int _height(SplayTreeNode<TreeItem> * node);

    void rotate(SplayTreeNode<TreeItem> * node){
        if (node != nullptr && node->_parent != nullptr) {
            if (node->_parent->_left == node) {
                SplayTreeNode<TreeItem> *parent = node->_parent;
                //SplayTreeNode<TreeItem> * left = node->left;
                SplayTreeNode<TreeItem> *middle = node->_right;
                SplayTreeNode<TreeItem> *right = node->_parent->_right;
                SplayTreeNode<TreeItem> *grandparent = node->_parent->_parent;
                node->_right = parent;
                node->_parent = grandparent;
                if (grandparent != nullptr) {
                    if (grandparent->_left == parent)
                        grandparent->_left = node;
                    else
                        grandparent->_right = node;
                }
                parent->_parent = node;
                parent->_left = middle;
                middle->_parent = parent;
            }
            else {
                SplayTreeNode<TreeItem> *parent = node->_parent;
                SplayTreeNode<TreeItem> * left = parent->_left;
                SplayTreeNode<TreeItem> *middle = node->_left;
                SplayTreeNode<TreeItem> *right = node->_right;
                SplayTreeNode<TreeItem> *grandparent = node->_parent->_parent;
                node->_left = parent;
                node->_parent = grandparent;
                if (grandparent != nullptr) {
                    if (grandparent->_left == parent)
                        grandparent->_left = node;
                    else
                        grandparent->_right = node;
                }
                parent->_parent = node;
                parent->_right = middle;
                middle->_parent = parent;
            }
        }
    }

    SplayTreeNode<TreeItem> * splay(SplayTreeNode<TreeItem> * node){
        if (node == nullptr || node->_parent == nullptr)
            return node;
        SplayTreeNode<TreeItem> * parent = node->_parent;
        SplayTreeNode<TreeItem> * grandparent = parent->_parent;
        if (grandparent == nullptr){
            rotate(node);
            return node;
        }
        bool zigzig = (grandparent->_left == parent) == (parent->_left == node);
        if (zigzig){
            rotate(parent);
            rotate(node);
        }
        else  {
            rotate(node);
            rotate(parent);
        }
        return splay(node);
    }

    SplayTreeNode<TreeItem> * _search(SplayTreeNode<TreeItem> * node, TreeItem item){
        if (node == nullptr)
            return nullptr;
        if (item == node->value())
            return splay(node);
        if (item < node->value() && node->_left != nullptr)
            return _search(node->_left, item);
        if (item > node->value() && node->_right != nullptr)
            return _search(node->_right, item);
        return splay(node);
    }

    std::pair<SplayTree<TreeItem>, SplayTree<TreeItem>> split(TreeItem key){
        if (_root == nullptr)
            return {SplayTree<TreeItem>(), SplayTree<TreeItem>()};
        SplayTreeNode<TreeItem> * temp = _search(_root, key);
        if (temp->value() == key)
            return {SplayTree<TreeItem> (temp->_left), SplayTree<TreeItem> (temp->_right)};
        if (temp->value() < key) {
            SplayTreeNode<TreeItem> * right = temp->_right;
            temp->_right = nullptr;
            return {SplayTree<TreeItem>(temp), SplayTree<TreeItem>(right)};
        }
        SplayTreeNode<TreeItem> * left = temp->_left;
        temp->_left = nullptr;
        return {SplayTree<TreeItem>(left), SplayTree<TreeItem>(temp)};
    }

public:
    explicit SplayTree(SplayTreeNode <TreeItem> * root = nullptr);

    void insert(TreeItem item);

    SplayTreeNode <TreeItem> * search(TreeItem item);

    void remove(SplayTreeNode <TreeItem> * z);

    std::vector<std::pair<TreeItem, TreeItem>> print();

    int height();
};


template<typename TreeItem>
void SplayTree<TreeItem>::_print(SplayTreeNode<TreeItem> *node, std::vector<std::pair<TreeItem, TreeItem>> &events) {
    if (node->_left != nullptr){
        events.push_back({node->value(),node->_left->value()});
        _print(node->_left, events);
    }
    if (node->_right != nullptr){
        events.push_back({node->value(),node->_right->value()});
        _print(node->_right, events);
    }
}

template<typename TreeItem>
SplayTree<TreeItem>::SplayTree(SplayTreeNode <TreeItem> * root) {
    _root = root;
}

template<typename TreeItem>
int SplayTree<TreeItem>::_height(SplayTreeNode<TreeItem> *node) {
    if (node == nullptr)
        return 0;
    return std::max(_height(node->_left), _height(node->_right)) + 1;
}

template<typename TreeItem>
int SplayTree<TreeItem>::height() {
    return _height(_root);
}

template<typename TreeItem>
SplayTreeNode<TreeItem>::SplayTreeNode(TreeItem item, SplayTreeNode<TreeItem> *left,
                                       SplayTreeNode<TreeItem> *right, SplayTreeNode<TreeItem> *parent) :
        _value(item),
        _left(left),
        _right(right),
        _parent(parent)
{}

template<typename TreeItem>
TreeItem SplayTreeNode<TreeItem>::value() {
    return _value;
}

template<typename TreeItem>
std::vector<std::pair<TreeItem, TreeItem>> SplayTree<TreeItem>::print() {
    std::vector<std::pair<TreeItem, TreeItem>> events;
    _print(_root, events);
    return events;
}

template<typename TreeItem>
SplayTreeNode<TreeItem> * SplayTree<TreeItem>::search(TreeItem item) {
    _root = _search(_root, item);
    if (_root != nullptr && _root->value() == item)
        return _root;
    return nullptr;
}

template<typename TreeItem>
void SplayTree<TreeItem>::insert(TreeItem item) {
    std::pair<SplayTree<TreeItem>, SplayTree<TreeItem>> split_res = split(item);
    _root = new SplayTreeNode<TreeItem>(item, split_res.first._root, split_res.second._root, nullptr);
}


#endif //ALGORITHMS_SPLAYTREE_HPP
