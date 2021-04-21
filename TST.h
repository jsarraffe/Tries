//
// Created by jsarraffe on 4/19/2021.
//

#ifndef PROJECT3B_TST_H
#define PROJECT3B_TST_H


#include <string>
#include <vector>

class tNode{
public:
    tNode(char c): _C(c),left(nullptr), middle(nullptr), right(nullptr), isEndOfWord(false){}
    char &getChar(){return _C;}
    tNode* &_left(){return this->left; }
    tNode* &_right(){return this->right; }
    tNode* &_middle(){return this->middle; }
    void setleft(tNode* n){this->left = n; }
    void setright(tNode* n){this->right = n; }
    void setmiddle(tNode* n){this->middle = n; }
    bool &_isEndOfWord(){return this->isEndOfWord;}

private:
    char _C;
    tNode *left;
    tNode *middle;
    tNode *right;
    bool isEndOfWord;
};
class TST {
public:


    TST(): root(nullptr){}

    tNode *getNode(std::string prefix);

    std::vector<std::string> startsWith(std::string prefix);
    std::vector<std::string> dfsWord(tNode *root);



    void dfsLocal(std::vector<std::string> &answer, std::string suffix, tNode *rt);

    std::string &_prefix(){return prefix;}

    void insert(std::string s);
    tNode *insertLocal(tNode *root, std::string s, int idx);

    tNode _nodeToDFSfrom(tNode *ntdfs){nodeToDFSfom = ntdfs;}

private:

    std::string prefix;
    tNode *nodeToDFSfom;
    tNode *root;


};


#endif //PROJECT3B_TST_H
