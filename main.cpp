#include <curl/curl.h>
#include <string>
#include <iostream>
#include "crawler.hpp"

int main() {
    // Initialize curl globally
    crawler crawler;
    crawler.start("https://leetcode.com/problems/find-if-path-exists-in-graph/description/");
    crawler.end();

    return 0;
}