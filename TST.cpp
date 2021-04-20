//
// Created by jsarraffe on 4/19/2021.
//

#include "TST.h"

tNode * TST::insertLocal(tNode *root, std::string s, int idx) {
    if(root == NULL)
    {
        root = new tNode(s[idx]);
    }
    if(idx < s.size()-1)
    {
        if (s[idx] < root->getChar()){
            root->setleft(( insertLocal(root->_left(), s, idx) ));
        }
        else if (s[idx] > root->getChar()){
            root->setright(insertLocal(root->_right(), s, idx)) ;
        }
        else {
            root->setmiddle(insertLocal(root->_middle(), s, idx + 1));
        }
    } else{
        root->_isEndOfWord() = true;
    }

    return root;
}


void TST::insert(std::string s) {

       this->root = insertLocal(this->root, s, 0);
}



