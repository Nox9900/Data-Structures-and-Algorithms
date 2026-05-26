/*
    REMVE Nth NODE FROM THE END OF THE LIST
    https://leetcode.com/problems/remove-nth-node-from-end-of-list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dump = new ListNode(0, head);
        ListNode* fast = dump;
        ListNode* slow = dump;
        for(int i=0; i<=n; i++)
            fast= fast->next;
        
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dump->next;
    }
};