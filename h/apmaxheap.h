#ifndef APMAXHEAP_h
#define APMAXHEAP_h

#include <iostream>
#include <vector>

template <class T>
class APMaxHeap {
private:
    std::vector<T*> arr;

public:
    APMaxHeap(); // Default constructor
    APMaxHeap(const APMaxHeap<T>& input); // Copy Constructor
    APMaxHeap(APMaxHeap<T>&& input); // Move Constructor
    ~APMaxHeap(); // Destructor
    APMaxHeap<T>& push(T input_element); // Add an element to the MAX HEAP
    APMaxHeap<T>& pop(); // Remove the Root Node in the Heap
    std::vector<T> show() const; // Show Heap elements
    APMaxHeap<T> operator+(const T& added_item) const; // Add an element to the MAX HEAP
    APMaxHeap<T>& operator=(const APMaxHeap<T>& input); // operatr -> = (Copy version) // Set heap to another heap
    APMaxHeap<T>& operator=(APMaxHeap<T>&& input); // operatr -> = (Move version) // Set heap to another heap
};

#include "apmaxheap.hpp"
#endif