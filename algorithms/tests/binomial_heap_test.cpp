//
// Created by darik on 4/12/2020.
//

#include "catch.hpp"
#include "../src/BinomialHeap.hpp"
#include <memory>

using std::shared_ptr;
using std::make_shared;

TEST_CASE("Insertion in Binomil Heap", "[BinomialHeap]")
{

}
TEST_CASE("Searching minimum in Binomial Heap", "[BinomialHeap]")
{
    BinomialHeap<int> heap;
    int minimum{1500};
    for(int i=0; i<100; ++i)
    {
        int element = rand() % 1500;
        if(element < minimum) minimum = element;
        heap.insert(element);
    }
    REQUIRE(heap.getMinimum()->_key == minimum);
}