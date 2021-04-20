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
    std::cout << "breakpoint" << std::endl;

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

    auto *td = new TST();

//    td->insert("foo");
//    td->insert("food");
//    td->insert("fun");
//    td->insert("funky");
//    td->insert("funny");


    td->insert("computing");
    td->insert("comprised");
    td->insert("consider");

    std::vector<std::string> answer;
    td->startsWith("co");


    std::cout <<"fuck you" << std::endl;


}