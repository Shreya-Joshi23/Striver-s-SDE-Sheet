class Solution {
public:

    vector<int>preorder;

    void solve(TreeNode* node){

        if(node==NULL)return;
        stack<TreeNode*>st;
        st.push(node);
        
        while(!st.empty()){
            auto n = st.top();
            preorder.push_back(n->val);
            st.pop();
             
            if(n->right){
                st.push(n->right);
            }
            if(n->left){
                st.push(n->left);
            }
           
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return preorder;
    }
};