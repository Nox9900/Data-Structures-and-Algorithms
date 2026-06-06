/*
    INTERSECTION OF TWO LINKED LIST
    https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            unordered_set<ListNode*> result;
            while(headA) {
                result.insert(headA);
                headA = headA->next;
            }
            while(headB) {
                if(result.count(headB)) return headB;
                headB = headB->next;
            }

            return nullptr;
        }
};