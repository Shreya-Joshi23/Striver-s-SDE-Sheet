//USING RECURSION
class Solution {
public:

    vector<int>v;

    void postorder(TreeNode* root){

        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        v.push_back(root->val);

    }

    vector<int> postorderTraversal(TreeNode* root) {

        postorder(root);
        return v;
        
    }
};

//USING TWO STACK
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {   
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left)st1.push(node->left);
            if(node->right)st1.push(node->right);
        }

        while(!st2.empty()){
            TreeNode* node=st2.top();
            st2.pop();
            ans.push_back(node->val);
        }

        return ans;

    }
};

//USING ONE STACK
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* curr=root;
        TreeNode* temp=NULL;

        vector<int>ans;

        while(curr!=NULL || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }else{
                temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    curr=temp;
                }
            }
        }

        return ans;
    }
};