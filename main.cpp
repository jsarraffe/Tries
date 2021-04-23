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


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "ERROR: Enter <filename   flag>";
        exit(1);
    }

    std::string filename = argv[1];
    std::cout << filename << std::endl;
    int flag = atoi(argv[2]);


    std::ifstream fp;
    std::string s;
    std::vector<std::string> words;

    fp.open(argv[1], std::ios::out | std::ios::app | std::ios::binary);

    while (fp >> s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !std::isalnum(c); }), s.end());
        std::string word;
        for (auto c : s) { word += std::tolower(c); }
        words.push_back(word);
        word.clear();
    }

    fp.close();
    auto *tst = new TST();
    auto *trie = new Trie();


    auto autoCompleteInitTST = std::chrono::steady_clock::now();
    tst->buildTST(words);
    auto autoCompleteFinishTST = std::chrono::steady_clock::now();
    auto autoCompleteTimeTST = std::chrono::duration_cast<std::chrono::microseconds>(
            autoCompleteFinishTST - autoCompleteInitTST);

    auto autoCompleteInitTrie = std::chrono::steady_clock::now();
    trie->buildTrie(words);
    auto autoCompleteFinishTrie = std::chrono::steady_clock::now();
    auto autoCompleteTimeTrie = std::chrono::duration_cast<std::chrono::microseconds>(
            autoCompleteFinishTrie - autoCompleteInitTrie);

    if(flag== 1){
        std::cout <<"----------------------"<<std::endl;
        std::cout <<"| ENTER '1' TO EXIT  |"<< std::endl;
        std::cout <<"----------------------"<<std::endl;
        std::cout << std::endl;
        std::cout <<  "Time taken to build the standard Trie is " << autoCompleteTimeTrie.count()
                  << " microseconds and space occupied by it is " << trie->_numNodesInTree()*26<< " pointers"<<std::endl;
        std::cout << "Time taken to build the BST based Trie is " << autoCompleteTimeTST.count()
                  << " microseconds and space occupied by it is " << tst->_numNodesInTree() << " pointers"<<std::endl;
        std::string userInput;
        while(true){
            std::cout<<std::endl;
            std::cout << "Enter search string: ";
            std::cin >> userInput;
            if(userInput == "1"){
                exit(1);
            }
            auto trieSearchInit = std::chrono::steady_clock::now();
            trie->getNode(userInput);
            auto trieSearchFinish = std::chrono::steady_clock::now();
            auto trieSearch = std::chrono::duration_cast<std::chrono::microseconds>(
                    trieSearchFinish - trieSearchInit);
            std::cout << "Time taken to search in the standard Trie is: "<< trieSearch.count() << " microseconds" <<std::endl;
            std::cout << "Auto-complete results using standard Trie are: ";


            auto trieAutoInit = std::chrono::steady_clock::now();
            auto ans = trie->startsWith(userInput);
            for (auto j : ans) {
                if(j==ans[ans.size()-1]){
                    std::cout << j << " ";
                }else{
                    std::cout << j << ", ";
                }
            }
            auto trieAutoFinish = std::chrono::steady_clock::now();
            auto trieAuto = std::chrono::duration_cast<std::chrono::microseconds>(
                    trieAutoFinish - trieAutoInit);

            std::cout << "\nTime taken to find auto-complete results in the standard Trie is "<< trieAuto.count() << " microseconds" <<std::endl<<std::endl;
            auto tstSearchInit = std::chrono::steady_clock::now();
            trie->getNode(userInput);
            auto tstSearchFinish = std::chrono::steady_clock::now();
            auto tstSearch = std::chrono::duration_cast<std::chrono::microseconds>(
                    tstSearchFinish - tstSearchInit);

            std::cout << "Time taken to search in the BST based Trie is "<< trieSearch.count() << " microseconds" <<std::endl;
            std::cout << "Auto-complete results using BST based Trie are: ";
            auto tstAutoInit = std::chrono::steady_clock::now();
            auto x = tst->startsWith(userInput);
            for (auto i : x) {
                if(i==x[x.size()-1]){
                    std::cout << i << " ";
                }else{
                    std::cout << i << ", ";
                }
            }
            auto tstAutoFinish = std::chrono::steady_clock::now();
            auto tstAuto = std::chrono::duration_cast<std::chrono::microseconds>(
                    tstAutoFinish - tstAutoInit);
            std::cout << "\nTime taken to find auto-complete results in the BST based Trie is "<< tstAuto.count() << " microseconds" <<std::endl;
        }
    }
    else if(flag = '2'){




        auto trieSAinit = std::chrono::steady_clock::now();
        for(auto word : words){
            trie->getNode(word)->_isEndOfWord();
        }
        auto trieSAfinish = std::chrono::steady_clock::now();
        auto trieAuto = std::chrono::duration_cast<std::chrono::microseconds>(
                trieSAfinish - trieSAinit);

        auto tstSAinit = std::chrono::steady_clock::now();
        for(auto word : words){
            tst->getNode(word)->_isEndOfWord();
        }
        auto tstSAfinish = std::chrono::steady_clock::now();
        auto tstAuto = std::chrono::duration_cast<std::chrono::microseconds>(
                tstSAfinish - tstSAinit);

        std::cout <<  "Time taken to build the standard Trie is " << autoCompleteTimeTrie.count()
                  << " microseconds and space occupied by it is " << trie->_numNodesInTree()*26<< " pointers"<<std::endl;
        std::cout << "Time taken to build the BST based Trie is " << autoCompleteTimeTST.count()
                  << " microseconds and space occupied by it is " << tst->_numNodesInTree() << " pointers"<<std::endl;
        std::cout << std::endl;


        std::cout << "Time taken to search all the strings in the standard Trie is  "<< trieAuto.count() << " microseconds" <<std::endl;
        std::cout << "Time taken to search all the strings in the BST based Trie is "<< tstAuto.count() << " microseconds" <<std::endl;

    }

}