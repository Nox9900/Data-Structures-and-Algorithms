/*
    ROTATE LIST
    https://leetcode.com/problems/rotate-list/description/
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head || !head->next || k==0) return head;
            int n =1;

            ListNode* tail = head;
            while(tail->next) {
                n++;
                tail = tail->next;
            }
            k = k%n;
            if(k==0) return head;
            tail->next = head;

            ListNode* tail2 = head;
            for(int i=0; i<n-k-1; i++) {
                tail2 = tail2->next;
            }

            ListNode* head2 = tail2->next;
            tail2->next = nullptr;
            return head2;

        }
};