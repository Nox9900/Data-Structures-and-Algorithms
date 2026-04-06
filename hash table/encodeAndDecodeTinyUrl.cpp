#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<int, string> urlMap;
    const string baseUrl = "http://tinyurl.com/";
    int id = 1;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urlMap[id] = longUrl;
        return baseUrl + to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id = stoi(shortUrl.substr(baseUrl.size()));
        return urlMap[id];
    }
};

//optimal solution

class Solution {
private:
    unordered_map<int, string> mp;
    int id = 0;
    string base = "http://tinyurl.com/";

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mp[id] = longUrl;
        return base + to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // Extract ID from URL
        int pos = shortUrl.find_last_of('/');
        int key = stoi(shortUrl.substr(pos + 1));
        return mp[key];
    }
};