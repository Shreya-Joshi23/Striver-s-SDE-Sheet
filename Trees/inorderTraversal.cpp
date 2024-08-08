
//USING STACK
class Solution {
public:

    vector<int>inorder;
    void solve(TreeNode* node){
        stack<TreeNode*>st;
        while(true){
            if(node){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty())break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }    
    }

    vector<int> inorderTraversal(TreeNode* root) {
       solve(root);
       return inorder;
    }
};


//USING RECURSION
class Solution {
public:
    vector<int>ans;
    
    void solve(TreeNode* root){
        if(root==NULL)return;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};