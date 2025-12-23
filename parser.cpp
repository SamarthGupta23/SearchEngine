//
// Created by samar on 19-12-2025.
//

#include "parser.hpp"

void parser::parse(string html) {
    char last = '>';
    bool script = false;
    bool style = false;
    string processedText = "";
    for (auto i : html) {
        if (i == '<') {
            last = '<';
            continue;
        }
        if (i == '>') {
            last = '>';
            continue;
        }

        if (last == '>') {
            processedText += i;
        }
    }

    this->text = processedText;
}

string parser::getText() {
    return text;
}

vector <string> parser::getLinks() {
    return this->links;
}

void parser::saveDoc(int id) {}

void parser::setAddress(string folderAddress) {
    this->address = folderAddress;
}