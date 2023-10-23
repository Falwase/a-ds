
#include "DocumentManager.h"
#include <iostream>

int main() {

    DocumentManager dm = DocumentManager();

    dm.addDocument("hi", 123, 5);
    dm.addPatron(456);

    std::cout << dm.search("hi") << std::endl;
}