/*
    LINKED LIST CYCLE II
    https://leetcode.com/problems/linked-list-cycle-ii
*/

#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x) , next(NULL) {}
};

class Solution {

    public:
        ListNode* detectCycle(ListNode* head) {
            if(!head || !head->next) return nullptr; 
            ListNode* slow = head;
            ListNode* fast = head;

            do {
                slow = slow->next;
                if(fast->next && fast->next->next)
                    fast = fast->next->next;
                else
                    return nullptr;
            }while(slow != fast);

            ListNode* start = head;
            while(start != slow) {
                start = start->next;
                slow = slow->next;
            }

            return start;
        
        }
};

//optimal solution
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};