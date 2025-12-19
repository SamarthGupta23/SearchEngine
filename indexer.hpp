//
// Created by samar on 19-12-2025.
//

#ifndef INDEXER_HPP
#define INDEXER_HPP


#include <bits/stdc++.h>
using namespace std;
class indexer {
    //data structure

public:
    void processDoc(string doc);
    string removeFiller(string doc);
    void editMap(string doc);
    string readDoc(string address);
};



#endif //INDEXER_HPP
