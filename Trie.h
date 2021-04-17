//
// Created by jsarraffe on 4/14/2021.
//

#ifndef PROJECT3B_TRIE_H
#define PROJECT3B_TRIE_H
#include <map>
#include <vector>

class TrieNode{
public:
     TrieNode(char c) : c(c), isEndOfWord(false), isVisited(false){
         children.resize(26, nullptr);
     }
     bool &_isEndOfWord(){return isEndOfWord;}
     char &_C(){return c;}
     bool &_isVisited(){return isVisited;}

     std::vector<TrieNode*> &getChildren(){return children;}


private:
    std::vector<TrieNode*> children;
    char c;
    bool isEndOfWord;
    bool isVisited;


};


class Trie {
public:
    Trie(): root(new TrieNode('0/')){}
    void insert(std::string word);
    void insertHelper(TrieNode* currNode, std::string word, int index);
    TrieNode* getNode(std::string word);
    TrieNode *getNodeHelper(TrieNode* curr, std::string word, int index);
    bool search(std::string word);
    std::vector<std::vector<TrieNode *>> dfs(TrieNode *z);
    std::vector<std::string> startWith(std::string prefix);
    std::vector<char> swHelper(TrieNode* r);
    TrieNode* root;

private:

};
#endif //PROJECT3B_TRIE_H
