
/*
    BINARY SERACH TREE ITERATOR
    https://leetcode.com/problems/binary-search-tree-iterator/submissions/
*/


class BSTIterator {
    stack<TreeNode*> st;
    void pushLeftNode(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftNode(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(node->right) pushLeftNode(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};