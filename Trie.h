//
// Created by jsarraffe on 4/14/2021.
//

#ifndef PROJECT3B_TRIE_H
#define PROJECT3B_TRIE_H
#include <map>
#include <vector>

class TrieNode{
public:
     TrieNode(char c) : c(c), isEndOfWord(false){
         children.resize(26, nullptr);
     }
     bool &_isEndOfWord(){return isEndOfWord;}
    char &_C(){return c;}
     std::vector<TrieNode*> &getChildren(){return children;}
private:
    std::vector<TrieNode*> children;
    char c;
    bool isEndOfWord;
};


class Trie {
public:
    Trie(): root(new TrieNode('0/')){}
    void insert(std::string word);
    void insertHelper(TrieNode* currNode, std::string word, int index);
    TrieNode* getNode(std::string word);
    TrieNode *getNodeHelper(TrieNode* curr, std::string word, int index);
    bool search(std::string word);
    std::vector<TrieNode*> startWith(std::string prefix);
    std::string swHelper(TrieNode* r, std::string prefix);
private:
    TrieNode* root;
};
#endif //PROJECT3B_TRIE_H
