/*
    IMPLEMENT TRIES PREFIX-TREE
    https://leetcode.com/problems/implement-trie-prefix-tree
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        unordered_map<char, TrieNode*> children; 
        bool endOfWord ;
        TrieNode() {
            endOfWord = false;
        } 
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch:word) {
            if(curr->children.find(ch) == curr->children.end())
                curr->children[ch] = new TrieNode;
            curr = curr->children[ch];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch:word) {
            if(curr->children.find(ch) == curr->children.end())
                return false;
            curr = curr->children[ch];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch:prefix){
            if(curr->children.find(ch) == curr->children.end()) 
                return false;
            curr = curr->children[ch];
        }
        return true;
    }
};