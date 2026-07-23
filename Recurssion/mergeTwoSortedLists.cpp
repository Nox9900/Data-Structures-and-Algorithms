

/*
    MERGE TWO SORTED LISTS
    https://leetcode.com/problems/merge-two-sorted-lists/
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dum(0);
        ListNode* tail = &dum;

        while(list1 != NULL && list2 != NULL) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dum.next;  
    }
};

