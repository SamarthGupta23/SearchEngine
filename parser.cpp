//
// Created by samar on 19-12-2025.
//

#include "parser.hpp"

void parser::parse(string html) {
    char last = '>';
    bool script = false;
    bool style = false;
    string check = "";
    string processedText = "";
    for (auto i : html) {
        if (check.size() < 9) {
            check += i;
        }
        else {
            check.erase(0 , 1);
            check += i;
            string stylOpen = check.substr(2 , 7);
            string stylClose = check.substr(1, 8);
            string scrptOpen = check.substr(1, 8);
            string scrptClose = check.substr(0, 9);
            if (stylOpen == "<style>" && style == false) {
                style = true;
            }
            if (scrptOpen == "<script>" && script == false) {
                script = true;
            }
            if (scrptClose == "</script>" && script == true) {
                script = false;
            }
            if (stylClose == "</style>" && style == true) {
                style = false;
            }
        }

        if (script || style) {
            continue;
        }
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
    for (auto i : processedText) {

    }
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