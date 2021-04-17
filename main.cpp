#include <iostream>


#include "Trie.h"


int main(int argc, char* argv[]) {

    if (argc != 1) {
        std::cout << "ERROR: You need to pass an argument";
    }


    auto *td = new Trie();

    td->insert("lesbian");
    td->insert("leseron");
    td->insert("less");

    auto z = td->getNode("les");
    std::cout << z->_C() << std::endl;


    td->startWith("les");


}