

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


class Solution {
public:
    TreeNode* sorted(vector<int>&ans,int start,int end){

        if(start>end) return nullptr;
        
        int mid= start+(end-start)/2;
        TreeNode* root = new TreeNode (ans[mid]);
        root->left=sorted(ans,start,mid-1);
        root->right= sorted(ans,mid+1,end);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ans;
          while(head){
            ans.push_back(head->val);
            head=head->next;
        }
        return sorted(ans,0,ans.size()-1);
    }
};