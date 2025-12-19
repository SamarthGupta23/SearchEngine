//
// Created by samar on 19-12-2025.
//
#include <curl/curl.h>
#include "crawler.hpp"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string get_html(const std::string& url) {
    CURL* curl = curl_easy_init();
    std::string html;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0"); // Set user agent

        CURLcode res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            return "";
        }

        curl_easy_cleanup(curl);
    }

    return html;
}

void crawler::start(string url) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    this->parser.setAddress("some address");
    this->docNumber= 0;
    while (docNumber < 100) {
        string html = getHtml(getNextUrl());
        this->parser.parse(html);
        int id = genID();
        editDict(id, url);
        this->html = parser.getText();
        vector <string> links = parser.getLinks();
        for (auto i : links) {
            urls.push(i);
        }
        saveHtml(id);
        updateGraph(links);
    }
}
void crawler::end() {
    curl_global_cleanup();
}
string crawler::getHtml(string url) {
    string response = get_html(url);
    cout << response << endl;
    return get_html(url);
}

void crawler::saveHtml(int id) {}
void crawler::updateGraph(vector<string> links) {}
void crawler::editDict(int id, string url) {}
string crawler::getNextUrl() {
    return "";
}

void crawler::parseHtml(string url) {}
int crawler::genID() {
    return 0;
}

