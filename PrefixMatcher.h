#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <vector>

using namespace std;

struct TrieNode
{
    TrieNode *children[2];
    int routerNumber;
    bool isEnd;
};


class PrefixMatcher
{
private:
    TrieNode* root;
    void doGetSuggestions(vector<string> *results, string partialWord);

public:
    void insert(string address, int routerNumber) ;// add a router address
    int selectRouter(string networkAddress);  // return the router with the longest matching prefix
    TrieNode* newNode();
    int checkWord(string word);
    
    PrefixMatcher(/* args */);
    ~PrefixMatcher();
};

#endif