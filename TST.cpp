//
// Created by jsarraffe on 4/19/2021.
//

#include "TST.h"
#include "iostream"
#include <vector>

tNode *TST::insertLocal(tNode *root, std::string s, int idx) {
    if (root == NULL) {
        root = new tNode(s[idx]);
    }
    if (idx >= s.size() - 1) {
        root->_isEndOfWord() = true;
    } else {
        if (s[idx] < root->getChar()) {
            root->setleft((insertLocal(root->_left(), s, idx)));
        } else if (s[idx] > root->getChar()) {
            root->setright(insertLocal(root->_right(), s, idx));
        } else {
            root->setmiddle(insertLocal(root->_middle(), s, idx + 1));
        }
    }
    return root;
}
void TST::insert(std::string s) {
    this->root = insertLocal(this->root, s, 0);
}

void TST::dfsLocal(std::vector<std::string> &answer, std::string suffix, tNode *rt) {
    if(rt != nullptr)
    {
        dfsLocal(answer, suffix, rt->_left());
        suffix += rt->getChar();
        if(rt->_isEndOfWord()){answer.push_back(prefix + suffix);}
        dfsLocal(answer, suffix, rt->_middle());
        suffix.pop_back();
        dfsLocal(answer, suffix, rt->_right());
    }


}
void TST::dfs(tNode *rt) {
    std::vector<std::string> answer;
    std::string suffix;
    dfsLocal(answer, suffix, rt->_left());
    dfsLocal(answer, suffix, rt->_middle());
    dfsLocal(answer, suffix, rt->_right());
    std::cout << "dkchz" <<std::endl;

}
tNode* TST::getNode(std::string prefix) {
    //first search for the node where the prefix matches, do dfs from there
    this->_prefix() = prefix;
    std::vector<std::string> answer;
    std::string suffix;
    tNode *prev = nullptr;
    tNode *curr = this->root;
    for (char c : prefix) {
        while (curr != nullptr && c != curr->getChar()) {
            prev = curr;
            if (c > curr->getChar()) {
                curr = curr->_right();
            } else {
                curr = curr->_left();
            }
        }
        if (curr != nullptr) {
            prev = curr;
            curr = curr->_middle();
        } else { std::cout << "You have failed"<<std::endl; }
    }
    this->_nodeToDFSfrom(prev);
    std::cout << "ah you gay" << std::endl;
   return prev;
}


tNode *TST::startsWith(std::string prefix) {
    auto *n = getNode(prefix);
    dfs(n);
    return nullptr;
}







