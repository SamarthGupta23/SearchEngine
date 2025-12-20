//
// Created by samar on 19-12-2025.
//

#ifndef CRAWLER_HPP
#define CRAWLER_HPP

#include "parser.hpp"
#include <bits/stdc++.h>
using namespace std;
class crawler {
    unordered_map <int , unordered_set <string>> linkGraph;
    int docNumber;
    parser parser;
    string html;
    unordered_map <int , string> dictToUrl;
    unordered_map <string , int> dictToId;
    queue <string> urls;
public:
    void start(string url);
    string getHtml(string url);
    void parseHtml(string url);
    int genID();
    void saveHtml(int id);
    void updateGraph(vector <string> links , int id);
    string getNextUrl();
    void end();
    void editDict(int id , string url);
};



#endif //CRAWLER_HPP
