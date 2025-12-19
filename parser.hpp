//
// Created by samar on 19-12-2025.
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include <bits/stdc++.h>
#include <string>
using namespace std;
class parser {
    string text;
    vector <string> links;
    string address; //parameter

public:
    void parse(string html);
    string getText();
    vector <string> getLinks();
    void saveDoc(int id);
    void setAddress(string folderAddress);
};



#endif //PARSER_HPP
