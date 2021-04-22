//
// Created by jsarraffe on 4/19/2021.
//

#include "TST.h"
#include "iostream"
#include <vector>

tNode *TST::insertLocal(tNode *rt, std::string s, int idx) {
    if (rt == NULL) {
        rt = new tNode(s[idx]);
        if (idx >= s.size() - 1) {
            rt->_isEndOfWord() = true;
            return rt;
        }
    }

    if (s[idx] < rt->getChar()) {
        rt->setleft((insertLocal(rt->_left(), s, idx)));
    } else if (s[idx] > rt->getChar()) {
        rt->setright(insertLocal(rt->_right(), s, idx));
    } else {
        rt->setmiddle(insertLocal(rt->_middle(), s, idx + 1));

    }

    return rt;
}
void TST::insert(std::string s) {
    this->root = insertLocal(this->root, s, 0);
}

void TST::dfsLocal(std::vector<std::string> &answer, std::string suffix, tNode *rt) {
    //dfs for leaf nodes in all subtrees, and those that are words
    if(rt == nullptr){
        return;
    }
    {
        dfsLocal(answer, suffix, rt->_left());
        suffix += rt->getChar();
        if(rt->_isEndOfWord()){
            answer.push_back(prefix + suffix);}
        dfsLocal(answer, suffix, rt->_middle());
        suffix.pop_back();
        dfsLocal(answer, suffix, rt->_right());
    }
}
std::vector<std::string> TST::dfsWord(tNode *rt) {
    std::vector<std::string> answer;
    std::string suffix;
    dfsLocal(answer, suffix, rt->_middle());
    return answer;

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
        } else { return nullptr; }
    }
    this->_nodeToDFSfrom(prev);
    //std::cout << "Debug test" << std::endl;
   return prev;
}
std::vector<std::string> TST::startsWith(std::string prefix) {
        auto *n = getNode(prefix);
        auto temp = n;

        if(getNode(prefix) == NULL){
            return std::vector<std::string>();
        }
        auto ans = dfsWord(n);
        if(temp->_isEndOfWord()){
            ans.insert(ans.begin(), prefix);
        }
        return ans;
}
void TST::buildTST(std::vector<std::string> words) {

    for(auto i : words){
        this->insert(i);
    }

}
