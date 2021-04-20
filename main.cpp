#include <iostream>
#include "Trie.h"
#include "TST.h"


int main(int argc, char* argv[]) {
    if (argc != 1) {
        std::cout << "ERROR: You need to pass an argument";
    }


    auto *td = new Trie();
//    td->insert("problem");
//    td->insert("processor");
//    td->insert("processors");
    td->insert("foo");
    td->insert("food");
    td->insert("fun");
    td->insert("funky");
    td->insert("funny");

//    td->insert("computing");
//    td->insert("comprised");
//    td->insert("consider");
    auto x = td->startWith("fun");
//
//
    for(auto z : x)
    {
        std::cout << z <<std::endl;
    }
    std::cout << "_________________"<<std::endl;

//    auto *td = new TST();
//
//    td->insert("foo");
//    td->insert("food");
//    td->insert("fun");
//    td->insert("funky");
//    td->insert("funny");
//
//
    std::cout <<" " << std::endl;


}