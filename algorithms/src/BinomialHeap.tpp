//
// Created by darik on 4/12/2020.
//

#include "BinomialHeap.hpp"

template<typename T>
void BinomialHeap<T>::sort() // bubble sort
{
    if (this->_head == nullptr) return;
    auto *cur = &(this->_head);
    while ((*cur)->_sibling != nullptr) {
        auto cur1 = cur;
        while ((*cur1)->_sibling != nullptr) {
            if ((*cur1)->_sibling->_degree < (*cur1)->_degree) {
                BinomialNode<T> *tmp = *cur1;
                (*cur1) = (*cur1)->_sibling;
                tmp->_sibling = (*cur1)->_sibling;
                (*cur1)->_sibling = tmp;
            }
            cur1 = &((*cur1)->_sibling);
        }
        cur = &((*cur)->_sibling);
    }
}

template<typename T>
void BinomialHeap<T>::merge() // merging of roots with equal degrees
{
    auto curH = &(this->_head);
    while ((*curH)->_sibling != nullptr) {
        if ((*curH)->_degree == (*curH)->_sibling->_degree) {
            if ((*curH)->_key <=
                (*curH)->_sibling->_key) { // root with greater key should become a child of root with lesser key
                auto tmp = (*curH)->_sibling;
                (*curH)->_sibling = tmp->_sibling;
                tmp->_sibling = (*curH)->_child;
                (*curH)->_child = tmp;
                tmp->_parent = *curH;
                (*curH)->_degree++;
            } else {
                auto tmp = (*curH)->_sibling;
                (*curH)->_sibling = tmp->_sibling;
                tmp->_sibling = *curH;
                *curH = tmp;
            }
        } else {
            curH = &((*curH)->_sibling);
        }
    }
}

template<typename T>
shared_ptr <BinomialHeap<T>> merge(shared_ptr <BinomialHeap<T>> H1, shared_ptr <BinomialHeap<T>> H2) // merging 2 heaps
{                                                            //and return pointer on new heap which is result of merging
    if (H1 == nullptr) return H2;
    if (H2 == nullptr) return H1;

    shared_ptr<BinomialHeap<T>> answer = make_shared<BinomialHeap<T>>();
    auto curH = &(answer->_head);
    auto curH1 = H1->head;
    auto curH2 = H2->head;
    while (curH1 != nullptr && curH2 != nullptr) {
        if (curH1->degree < curH2->degree) {
            (*curH) = curH1;
            curH = &((*curH)->_sibling);
            curH1 = curH1->sibling;
        } else {
            (*curH) = curH2;
            curH = &((*curH)->_sibling);
            curH2 = curH2->sibling;
        }
    }
    if (curH1 == nullptr) {
        while (curH2 != nullptr) {
            *(curH) = curH2;
            curH = &((*curH)->_sibling);
            curH2 = curH2->sibling;
        }
    } else {
        while (curH1 != nullptr) {
            *(curH) = curH1;
            curH = &((*curH)->_sibling);
            curH1 = curH1->sibling;
        }
    }
    curH = &(answer->_head);
    merge(answer);
    answer->sort();
    return answer;
}

template<typename T>
void BinomialHeap<T>::insert(T value) //creating new heap with only root with key=value and merging this heap and new one
{
    shared_ptr<BinomialNode<T>> new_node = make_shared<BinomialNode<T>>(value);
    if (this->_head == nullptr) this->_head = new_node;
    else {
        new_node->_sibling = _head;
        _head = new_node;
        this->merge();
    }
}

template<typename T>
shared_ptr<BinomialNode<T>> BinomialHeap<T>::getMinimum() // the minimum key is in the one of root nodes
{
    auto answer = this->_head;
    auto curH = this->_head;
    while (curH != nullptr) {
        if (curH->_key < answer->_key) {
            answer = curH;
        }
        curH = curH->_sibling;
    }
    return answer;
}

template<typename T>
shared_ptr <BinomialNode<T>> BinomialHeap<T>::extractMin() {
    if (this->_head == nullptr) return nullptr;

    auto answer = this->_head;
    auto curH = this->_head;
    auto previous = this->_head;

    while (curH->_sibling != nullptr) // finding root with min key
    {
        if (curH->_sibling->_key < answer->_key) {
            answer = curH->_sibling;
            previous = curH;
        }
        curH = curH->_sibling;
    }

    if (answer == previous) {
        this->_head = answer->_sibling;
    } else {
        previous->_sibling = answer->_sibling;
    }

    shared_ptr<BinomialHeap<T>> new_heap = make_shared<BinomialHeap<T>>(); // creating new heap where roots are children
    //  of root with min key
    auto cur = answer->_child;
    auto cur_new = &new_heap->_head;

    while (cur != nullptr) {
        cur->_parent = nullptr;
        *cur_new = cur;
        cur_new = &((*cur_new)->_sibling);
        cur = cur->_sibling;
    }

    auto merged_heap = merge(this, new_heap); // merging this heap and new one
    this->_head = merged_heap->_head;
    return answer;
}

template<typename T>
void BinomialHeap<T>::decreaseKey(shared_ptr <BinomialNode<T>> node, const T &k) {
    if (k > *node->key) return; // method can only decrease value
    *node->key = k;
    while (node->parent != nullptr && node->parent->key > node->key) {
        auto tmp = *node;
        node->key = node->parent->key;
        node = node->parent;
        node->key = tmp.key;
    }
}

template<typename T>
void BinomialHeap<T>::remove(shared_ptr <BinomialNode<T>> node) {
    this->decreaseKey(node, T()); // set the key of removing node to min possible
    this->extractMin();
    this->sort();
}
