
#include "Autocomplete.h"

#include <string>
#include <vector>
#include <iostream>

int main() {

    Autocomplete* ac = new Autocomplete();

    ac->insert("cat");
    ac->insert("boat");
    ac->insert("car");
    ac->insert("c");

    vector<string> print = ac->getSuggestions("b");

// print
    std::cout << "The vector elements are : ";

    for(int i=0; i < print.size(); i++) {
        std::cout << print.at(i) << ' ';
    }
}