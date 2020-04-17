//
// Created by darik on 4/12/2020.
//

#include "catch.hpp"
#include "../src/BinomialHeap.hpp"
#include <memory>

using std::shared_ptr;
using std::make_shared;

TEST_CASE("Insertion in Binomil Heap", "[BinomialHeap]") {
    BinomialHeap<int> heap;
    heap.insert(5);
    CHECK(heap._head->_key == 5);
    heap.insert(7);
    CHECK(heap._head->_child->_key == 7);
    heap.insert(3);
    CHECK(heap._head->_key == 3);
    for (int i = 0; i < 12; ++i) {
        heap.insert(rand() % 500);
    }
    CHECK(heap._head->_degree == 0);
    heap.insert(500);
    CHECK(heap._head->_degree == 4);
}

TEST_CASE("Searching minimum in Binomial Heap", "[BinomialHeap]") {
    BinomialHeap<int> heap;
    int minimum{1500};
    for (int i = 0; i < 100; ++i) {
        int element = rand() % 1500;
        if (element < minimum) minimum = element;
        heap.insert(element);
    }
    REQUIRE(heap.getMinimum()->_key == minimum);
}

TEST_CASE("Extracting minimum in Binomial Heap", "[BinomialHeap]") {
    BinomialHeap<int> heap;
    for (int i = 0; i < 100; ++i) {
        heap.insert(i);
    }

    CHECK(heap.extractMin()->_key == 0);
    CHECK(heap.getMinimum()->_key == 1);

    for (int i = 0; i < 10; ++i) {
        heap.extractMin();
    }
    CHECK(heap.getMinimum()->_key == 11);
}

TEST_CASE("Final test Binomial Heap", "[BinomialHeap]")
{
    BinomialHeap<int> heap1, heap2;
    for(int i=0; i<100; ++i)
    {
        int element = rand()%15000;
        heap1.insert(element);
        heap2.insert(element);
    }

    for(int i=0; i<5; ++i)
    {
        int element = heap1.extractMin()->_key;
        heap1.insert(element);
    }

    CHECK(heap1.getMinimum()->_key == heap2.getMinimum()->_key);

}