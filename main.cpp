#include <iostream>
#include "Trie.h"
#include "TST.h"

#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <string>
#include <functional>
#include <algorithm>




int main(int argc, char* argv[]) {
    if (argc != 1) {
        std::cout << "ERROR: You need to pass an argument";
    }
    std::ifstream fp( "test.txt" );
    std::string s;
    std::vector<std::string> words;

    while (fp>> s){
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !std::isalnum(c); }), s.end());
        std::string word;
        for(auto c : s) { word += std::tolower(c);}
        words.push_back(word);
        word.clear();
    }
    std::cout << " " << std::endl;

    //ask for help

//
//    auto *td = new Trie();
//    td->insert("problem");
//    td->insert("processor");
//    td->insert("processors");
//    td->insert("foo");
//    td->insert("food");
//    td->insert("fun");
//    td->insert("funky");
//    td->insert("funny");

//    td->insert("computing");
//    td->insert("comprised");
//    td->insert("consider");
//    auto x = td->startWith("fun");
//
//
//    for(auto z : x)
//    {
//        std::cout << z <<std::endl;
//    }
//    std::cout << "_________________"<<std::endl;

    auto *tst = new TST();
    auto *trie = new Trie();

//    tst->insert("foo");
//    tst->insert("food");
//    tst->insert("fun");
//    tst->insert("funny");
//    tst->insert("funky");
//    tst->insert("computing");
//    tst->insert("comprised");
//    tst->insert("consider");
//    tst->insert("problem");
//    tst->insert("processor");
//    tst->insert("processors");


    trie->insert("foo");
    trie->insert("food");
    trie->insert("fun");
    trie->insert("funny");
    trie->insert("funky");
    std::vector<std::string> answer;

//    std::cout << "For TST" << std::endl;
//    for(auto i : tst->startsWith("pro"))
//    {
//        std::cout << i << " ";
//    }
    auto x = trie->startsWith("fun");
    std::cout << "For TrieNode" << std::endl;
    for(auto j : trie->startsWith("fo"))
    {
        std::cout << j << " ";
    }


    std::cout <<" " << std::endl;


}