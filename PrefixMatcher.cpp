
#include "PrefixMatcher.h"

#include <string>
#include <vector>
#include <iostream>

/*
vector<string> PrefixMatcher::int selectRouter(string networkAddress); {

    vector<string> results;

    doGetSuggestions(&results, partialWord);

    results.erase(std::remove(results.begin(), results.end(), partialWord), results.end());

    return results;
}

void PrefixMatcher::doGetSuggestions(vector<string> *results, string partialWord) {

    //find end node of input partialWord
    TrieNode* subRoot = checkWord(partialWord);

    std::string nextchar;

    for (int i = 0; i < 26; i++) {
        if (subRoot->children[i] == nullptr) {
            continue;
        }

        nextchar = i + 97;
        doGetSuggestions(results, partialWord + nextchar);
    }

    if (subRoot->isEnd) {
        results->push_back(partialWord);
    } 
} */

void PrefixMatcher::insert(string address, int routerNumber) {
    TrieNode *temp = root;
 
    for (int i = 0; i < address.length(); i++) {
        int index = address[i];
        if (!temp->children[index])
            temp->children[index] = newNode();
 
        temp = temp->children[index];
    }
 
    // mark last node as leaf
    temp->isEnd = true;
    temp->routerNumber = routerNumber;
}

int PrefixMatcher::checkWord(string word) {
    struct TrieNode *temp = root;
 
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i];
        if (!temp->children[index])
            return temp->routerNumber;
 
        temp = temp->children[index];
    }

    return temp->routerNumber;
}

TrieNode* PrefixMatcher::newNode() {
    TrieNode* node = new TrieNode;
    for (int i=0; i<2; i++) {
        node->children[i] = NULL;
    }
    node->isEnd = false;
    node->routerNumber = -1;

    return node;
}

PrefixMatcher::PrefixMatcher() {
    TrieNode* node = new TrieNode;
    for (int i=0; i<2; i++) {
        node->children[i] = NULL;
    }
    node->isEnd = false;

    root = node;
}

PrefixMatcher::~PrefixMatcher() {

}