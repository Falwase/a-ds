#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;
};


class Autocomplete
{
private:
    TrieNode* root;
    void doGetSuggestions(vector<string> *results, string partialWord);

public:
    vector<string> getSuggestions(string partialWord);  // return the known words that start with partialWord
    void insert(string word); // add a word to the known words
    TrieNode *newNode();
    TrieNode* checkWord(string word);
    
    Autocomplete(/* args */);
    ~Autocomplete();
};

#endif