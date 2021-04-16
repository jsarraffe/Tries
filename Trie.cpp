//
// Created by jsarraffe on 4/14/2021.
//

#include <vector>
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

std::vector<TrieNode *> Trie::startWith(std::string prefix) {

    auto * n = getNode(prefix);
    std::vector<std::string> answer;

    swHelper(n, prefix);

}

std::string Trie::swHelper(TrieNode *r, std::string prefix) {

    std::string solution;
    std::vector<std::string> s;
    auto *curr = r;
    std::string newPref = prefix;
    for(int i = 0; i < r->getChildren().size(); i++)
    {
        if(curr->getChildren()[i]->_isEndOfWord()){
            s.push_back(solution);
            solution = prefix;
        }

        if(curr->getChildren()[i] != NULL){
            newPref += curr->getChildren()[i]->_C();
            curr = curr->getChildren()[i];
        }
    }
}





