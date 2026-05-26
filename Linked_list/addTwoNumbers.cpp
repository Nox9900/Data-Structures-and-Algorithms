/*
    ADD TWO NUMBERS
    https://leetcode.com/problems/add-two-numbers
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dump = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* curr = dump;
        int carry = 0;

        while(p || q){
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = x+y+carry;
            carry = sum/10;

            curr->next = new ListNode(sum%10);
            curr = curr->next;

            if(p) p = p->next;
            if(q) q = q->next;
        }

        if(carry > 0) {
            curr->next = new ListNode(carry);
        }

        ListNode* result = dump->next;
        delete dump;
        return result;

    }
};