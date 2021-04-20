//
// Created by jsarraffe on 4/14/2021.
//

#include <vector>
#include <iostream>
#include "Trie.h"

void Trie::insert(std::string word) {
   insertHelper(root, word, 0);
}
void Trie::insertHelper(TrieNode *currNode, std::string word, int index) {
    if(index == word.length()){
        currNode->_isEndOfWord() = true;
        return;
    }
    char c = word[index];
    if(currNode->getChildren()[c-'a'] == NULL){
        currNode->getChildren()[c - 'a'] = new TrieNode(c);
        currNode = currNode->getChildren()[c-'a'];
    }else{
        currNode = currNode->getChildren()[c-'a'];
    }
    insertHelper(currNode, word, index + 1);

}
TrieNode* Trie::getNode(std::string word) {
    return getNodeHelper(root, word, 0);
}
TrieNode *Trie::getNodeHelper(TrieNode* curr, std::string word, int index) {
    if(index == word.length()){
        return curr;
    }
    char c = word[index];
    if(curr->getChildren()[c - 'a'] == NULL){
        return NULL;
    }
    else{
        curr = curr->getChildren()[c - 'a'];
    }
    return getNodeHelper(curr, word, index + 1);
}
bool Trie::search(std::string s) {
    auto *node = getNode(s);
    return node != NULL && node->_isEndOfWord();
}
std::vector<TrieNode *> Trie::getNeihbors(TrieNode* n) {
    std::vector<TrieNode*> neihbors;
    for(auto &c : n->getChildren()){
        if(c != NULL){
            neihbors.push_back(c);
        }
    }
    return neihbors;
}
std::vector<std::string> Trie::startWith(std::string prefix) {
    auto n = getNode(prefix);
    this->prefix = prefix;
    std::vector<std::string> answer;
    std::string suffix;
    if(n == NULL){
        return answer;
    }
//    if(n = getNode(prefix)){
//        answer.push_back(prefix);
//    }
    auto nei = getNeihbors(n);
    for (auto *v: nei){
        dfsLocal(v, answer, suffix);}
    return answer;
}
void Trie::dfsLocal(TrieNode *r, std::vector<std::string> &answer, std::string &suffix) {

    if(r->_isEndOfWord()){
        if(r = getNode(prefix)){
            answer.push_back(prefix);
        }
        suffix += r->_C();
        answer.push_back(prefix + suffix);
        if(getNeihbors(r).empty()){
            suffix.clear();
            return;
        }
    }
    auto w = getNeihbors(r);
    for(auto i : w){
                if(!r->_isEndOfWord()){
                    suffix += r->_C();
                }
            dfsLocal(i, answer, suffix);
    }
}


