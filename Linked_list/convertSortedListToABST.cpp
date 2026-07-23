

/*
    CONVERT A SORTED LIST TO A BINARY SEARCH TREE
    https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
*/

class Solution {

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        ListNode* node = head;
        while(node) {
            size++;
            node = node->next;
        }
        current = head;
        return build(0, size -1);
    }

private:
    ListNode* current;
    TreeNode* build(int left, int right) {
        if(left > right)
            return nullptr;

        int mid = left + (right-left) / 2;
        TreeNode* leftChild = build(left, mid-1);
        
        TreeNode* root = new TreeNode(current->val);
        current = current->next;

        root->left = leftChild;
        root->right = build(mid+1, right);

        return root;
    }
};