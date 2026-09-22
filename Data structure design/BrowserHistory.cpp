#include<bits/stdc++.h>
using namespace std;

class BrowserHistory {
    struct Node {
        string url;
        Node* next;
        Node* prev;
        Node(string e) : url(e), next(nullptr), prev(nullptr) {}
    };

    Node* current;

public: 
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* node = new Node(url);
        current->next = node;
        node->prev = current;
        current = node;
    }

    string back( int steps ) {
        while(steps > 0 && current->prev) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while(steps > 0 && current->next) {
            current = current->next;
            steps--;
        }
        return current->url;
    }

};