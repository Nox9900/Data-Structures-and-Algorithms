#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int key;
        int value; 
        Node* prev;
        Node* next;
        Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev; 
    } 

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) {
            return -1;
        }
        Node* node = map[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            map[key] = newNode;
            addNode(newNode);
        }

        if(map.size() > capacity) {
            Node* tail = popTail();
            map.erase(tail->key);
            delete tail;
        }
    }
};