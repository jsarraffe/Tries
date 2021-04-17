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

std::vector<std::string> Trie::startWith(std::string prefix) {
    auto start =  this->getNode("les");
    std::vector<TrieNode*> rChildren;
    for (auto *c : root->getChildren()){
        if(c != NULL){
            rChildren.push_back(c);
        }
    }
    std::vector<std::vector<std::vector<TrieNode*>>> answer;
    for(int i = 0; i < start->getChildren().size();i++){
        answer.push_back(dfs(start->getChildren()[i]));
    }

}
std::vector<std::vector<TrieNode *>>Trie::dfs(TrieNode * z) {

    std::vector<TrieNode *> d;


    for(int i = 0; i < 26; i++)
    {
        if(z->getChildren()[i] != NULL && z->getChildren()[i]->_isVisited() != true){
            z->getChildren()[i]->_isVisited() = true;
        };
    }

    for(auto *x : z->getChildren()){
        if(x != NULL && x->_isVisited() != true) {
            x->_isVisited() = true;
            d.push_back(x);
            dfs(x);
        }

    }

}
