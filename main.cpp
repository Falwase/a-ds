
#include "PrefixMatcher.h"

#include <string>
#include <vector>
#include <iostream>

int main() {

    PrefixMatcher* ac = new PrefixMatcher();

    std::cout << ac->checkWord("001100") << std::endl;

    ac->insert("001100", 1);
    ac->insert("0111001", 2);

    std::cout << ac->checkWord("0011001") << std::endl;
}