#include "Heap.tpp"

#include <iostream>

int main() {

    std::vector<int> vect; 
  
    vect.push_back(10); 
    vect.push_back(20); 
    vect.push_back(30); 

    Heap<int> h = Heap<int>(vect);

    h.remove(30);
    h.insert(40);

    std::cout << h.getMin() << std::endl;

    h.remove(10);

    std::cout << h.getMin() << std::endl;
}