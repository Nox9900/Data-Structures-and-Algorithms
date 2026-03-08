
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