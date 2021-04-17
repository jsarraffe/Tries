#include <iostream>


#include "Trie.h"


int main(int argc, char* argv[]) {

    if (argc != 1) {
        std::cout << "ERROR: You need to pass an argument";
    }


    auto *td = new Trie();

    td->insert("asshole");
    td->insert("assthee");

    auto x = td->startWith("work");
    std::cout << "dude" << std::endl;


}