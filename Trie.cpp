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
    if (index == word.length()) {
        currNode->_isEndOfWord() = true;
        return;
    }
    char c = word[index];
    if (currNode->getChildren()[c - 'a'] == NULL) {
        currNode->getChildren()[c - 'a'] = new TrieNode(c);
        currNode = currNode->getChildren()[c - 'a'];
    } else {
        currNode = currNode->getChildren()[c - 'a'];
    }
    insertHelper(currNode, word, index + 1);

}

TrieNode *Trie::getNode(std::string word) {
    return getNodeHelper(root, word, 0);
}

TrieNode *Trie::getNodeHelper(TrieNode *curr, std::string word, int index) {
    if (index == word.length()) {
        return curr;
    }
    char c = word[index];
    if (curr->getChildren()[c - 'a'] == NULL) {
        return NULL;
    } else {
        curr = curr->getChildren()[c - 'a'];
    }
    return getNodeHelper(curr, word, index + 1);
}

bool Trie::search(std::string s) {
    auto *node = getNode(s);
    return node != NULL && node->_isEndOfWord();
}

std::vector<TrieNode *> Trie::getNeihbors(TrieNode *n) {
    std::vector<TrieNode *> neihbors;
    for (auto &c : n->getChildren()) {
        if (c != NULL) {
            neihbors.push_back(c);
        }
    }
    return neihbors;
}

std::vector<std::string> Trie::startsWith(std::string prefix) {
    auto n = getNode(prefix);
    this->prefix = prefix;
    OGprefix = prefix;
    std::vector<std::string> answer;
    std::string suffix;
    if (n == NULL) {
        return answer;
    }

    dfsLocal(n, answer, suffix);
    return answer;
}

void Trie::dfsLocal(TrieNode *r, std::vector<std::string> &answer, std::string &suffix) {


    if(r->_isEndOfWord()){
        answer.push_back(prefix + suffix);
    }
    for(auto p : getNeihbors(r))
    {
        suffix += p->_C();
        dfsLocal(p, answer, suffix);
        suffix.pop_back();

    }















//    if(r->_isEndOfWord()){
//        answer.push_back(prefix + suffix);
//    }
//    auto w = getNeihbors(r);
//    for(auto i : w){
//        if(i != nullptr){
//            suffix += i->_C();
//            dfsLocal(i, answer, suffix);
//            suffix.pop_back();
//        }
//    }
}

void Trie::buildTrie(std::vector<std::string> words) {

    for (auto i : words) {
        this->insert(i);
    }

}


