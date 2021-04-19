#include <iostream>


#include "Trie.h"


int main(int argc, char* argv[]) {

    if (argc != 1) {
        std::cout << "ERROR: You need to pass an argument";
    }


    auto *td = new Trie();


    td->insert("problem");
    td->insert("processor");
    td->insert("processors");

    auto x = td->startWith("pro");


    for(auto z : x)
    {
        std::cout << z <<std::endl;
    }
    std::cout << "asshole"<<std::endl;

}