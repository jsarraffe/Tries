//
// Created by jsarraffe on 4/19/2021.
//

#include "TST.h"
#include "iostream"
#include <vector>

tNode *TST::insertLocal(tNode *rt, std::string s, int idx) {
    if (rt == NULL) {
        if(idx > s.size() - 1) { this->_numNodesInTree()-s.size();return rt;}
        rt = new tNode(s[idx]);
        this->_numNodesInTree()++;
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
        if(idx == s.size()-1) {rt->_isEndOfWord() = true;}
        rt->setmiddle(insertLocal(rt->_middle(), s, idx + 1));
    }
    return rt;
}
void TST::insert(std::string s) {


    this->root = insertLocal(this->root, s, 0);
}
void TST::dfsLocal(std::vector<std::string> &answer, std::string suffix, tNode *rt) {
    if(rt == nullptr){
        return;
    }
    {
        dfsLocal(answer, suffix, rt->_left());
        suffix += rt->getChar();
        if(rt->_isEndOfWord() && rt->getChar()){
            answer.push_back(prefix + suffix);
        }
        dfsLocal(answer, suffix, rt->_middle());

        suffix.pop_back();
        dfsLocal(answer, suffix, rt->_right());
    }
}
std::vector<std::string> TST::dfsWord(tNode *rt) {
    //traversal given a given node. Used for autocomplete, dfs until for nodes for all children
    std::vector<std::string> answer;
    std::string suffix;
    dfsLocal(answer, suffix, rt->_middle());
    return answer;

}
tNode* TST::getNode(std::string prefix) {
    //returns the node if it is in the data strucutre
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
