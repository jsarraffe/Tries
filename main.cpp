#include <iostream>


#include "Trie.h"


int main(int argc, char* argv[]){

    if(argc != 1){
        std::cout << "ERROR: You need to pass an argument";
    }


    auto *td = new Trie();

    td->insert("cab");
    td->insert("cad");


    std::cout << td->getNode("ca")->_C();



}