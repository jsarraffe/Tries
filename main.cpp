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
#include <algorithm>


void remove_duplicates(std::vector<std::string>& vec)
{
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "ERROR: Enter <filename   flag>";
//        exit(1);
    }
    std::string filename = argv[1];
    std::cout<<filename<<std::endl;
    int flag = atoi(argv[2]);
    std::ifstream fp;
    std::string s;
    std::vector<std::string> words;

    fp.open (argv[1], std::ios::out | std::ios::app | std::ios::binary);

    while (fp>> s ){
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !std::isalnum(c); }), s.end());
        std::string word;
        for(auto c : s) { word += std::tolower(c);}

        if(std::find(words.begin(), words.end(), word) == words.end()) {
            words.push_back(word);
            word.clear();
        } else {
            continue;
        }
    }

    fp.close();
    std::cout << " " << std::endl;

    auto *tst = new TST();
    auto *trie = new Trie();

////
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

//    std::cout << "Time taken to build the standard Trie is " <<  autoCompleteTimeTrie.count() << " microseconds and space occupied by it is ";
//    std::cout << std::endl;


    //tst->buildTST(words);
//   trie->buildTrie(words);
    std::string prefix = "go";


    std::cout << std::endl;



    tst->insert("going");

    tst->insert("go");

    tst->insert("good");

    tst->insert("got");

//    trie->insert("sawn");
//    trie->insert("sheltered");
//    trie->insert("shield");
//    trie->insert("shield");



    auto x =  tst->startsWith(prefix);


    std::cout << "For TST" << std::endl;
    for(auto i : x)
    {
        std::cout << i << ", ";
    }
    std::cout<<std::endl;
    std::cout << "For TrieNode:" << std::endl;
    int i ;
    for(auto j : trie->startsWith(prefix))
    {
        std::cout << j << ", "; i++;
    }
//    std::cout<<i<<std::endl;
    std::cout <<" " << std::endl;


}