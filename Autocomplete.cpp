
#include "Autocomplete.h"

#include <string>
#include <vector>
#include <iostream>

vector<string> Autocomplete::getSuggestions(string partialWord) {

    vector<string> results;

    doGetSuggestions(&results, partialWord);

    results.erase(std::remove(results.begin(), results.end(), partialWord), results.end());

    return results;
}

void Autocomplete::doGetSuggestions(vector<string> *results, string partialWord) {

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
}

void Autocomplete::insert(string word) {
    TrieNode *temp = root;
 
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (!temp->children[index])
            temp->children[index] = newNode();
 
        temp = temp->children[index];
    }
 
    // mark last node as leaf
    temp->isEnd = true;
}

TrieNode* Autocomplete::checkWord(string word) {
    struct TrieNode *temp = root;
 
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (!temp->children[index])
            return nullptr;
 
        temp = temp->children[index];
    }
 
    return temp;
}

TrieNode* Autocomplete::newNode() {
    TrieNode* node = new TrieNode;
    for (int i=0; i<26; i++) {
        node->children[i] = NULL;
    }
    node->isEnd = false;

    return node;
}

Autocomplete::Autocomplete() {
    TrieNode* node = new TrieNode;
    for (int i=0; i<26; i++) {
        node->children[i] = NULL;
    }
    node->isEnd = false;

    root = node;
}

Autocomplete::~Autocomplete() {

}