#include <iostream>
#include "Trie.h"
#include "TST.h"
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <chrono>
#include <functional>
#include <algorithm>




int main(int argc, char* argv[]) {
    if (argc != 1) {
        std::cout << "ERROR: You need to pass an argument";
    }
    std::ifstream fp( "test2.txt" );
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

    auto *tst = new TST();
    auto *trie = new Trie();

//    for(auto word : words)
//    {
//        tst->insert(word);
//    }
//
//    for(auto word : words)
//    {
//        trie->insert(word);
//    }


    tst->insert("scheduling");
    tst->insert("set");
    tst->insert("so");
    tst->insert("specific");
    tst->insert("sum");

    trie->insert("scheduling");
    trie->insert("set");
    trie->insert("so");
    trie->insert("specific");
    trie->insert("sum");


    std::string prefix = "s";


    std::cout << "For TST" << std::endl;
    for(auto i : tst->startsWith(prefix))
    {
        std::cout << i << ", ";
    }
    std::cout<<std::endl;
    std::cout << "For TrieNode:" << std::endl;
    for(auto j : trie->startsWith(prefix))
    {
        std::cout << j << ", ";
    }


    std::cout <<" " << std::endl;


}