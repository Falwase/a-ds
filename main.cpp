
#include "DocumentManager.h"
#include <iostream>

int main() {

    DocumentManager dm = DocumentManager();

    dm.addDocument("hi", 123, 1);
    dm.addPatron(456);

    std::cout << dm.search("hi") << std::endl;

    std::cout << dm.borrowDocument(123, 456) << std::endl;
    dm.returnDocument(123, 456);
    std::cout << dm.borrowDocument(123, 456) << std::endl;
}