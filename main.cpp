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


//    auto autoCompleteInitTST = std::chrono::steady_clock::now();
//    tst->buildTST(words);
//    auto autoCompleteFinishTST = std::chrono::steady_clock::now();
//    auto autoCompleteTimeTST =  std::chrono::duration_cast<std::chrono::microseconds>(autoCompleteFinishTST - autoCompleteInitTST);
//    std::cout << "Time taken to build the standard Trie is " <<  autoCompleteTimeTST.count() << " microseconds and space occupied by it is ";
//
//    std::cout<<std::endl;
//
//    auto autoCompleteInitTrie = std::chrono::steady_clock::now();
//    trie->buildTrie(words);
//    auto autoCompleteFinishTrie = std::chrono::steady_clock::now();
//    auto autoCompleteTimeTrie =  std::chrono::duration_cast<std::chrono::microseconds>(autoCompleteFinishTrie - autoCompleteInitTrie);
//
//    std::cout << "Time taken to build the standard Trie is " <<  autoCompleteTimeTrie.count() << " microseconds and space occupied by it is ";

   std::cout << std::endl;
    //tst->buildTST(words);
//   trie->buildTrie(words);

    tst->insert("foo");
    tst->insert("fo");
    tst->insert("as");
    tst->insert("food");
    tst->insert("fun");
    tst->insert("funky");
    tst->insert("funny");


    trie->insert("foo");
    trie->insert("fo");
    trie->insert("as");
    trie->insert("food");
    trie->insert("fun");
    trie->insert("funky");
    trie->insert("funny");



    tst->insert("scheduling");
    tst->insert("set");
    std::cout << " " << std::endl;
    tst->insert("so");
    tst->insert("specific");
    tst->insert("sum");

    trie->insert("scheduling");
    trie->insert("set");
    trie->insert("so");
    std::cout << " " << std::endl;
    trie->insert("specific");
    trie->insert("sum");

    trie->insert("comprised");
    trie->insert("computing");
    trie->insert("consider");
    tst->insert("comprised");
    tst->insert("computing");
    tst->insert("consider");

    tst->insert("processors");
    tst->insert("processor");
    tst->insert("problem");
    trie->insert("processors");
    trie->insert("processor");
    trie->insert("problem");

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