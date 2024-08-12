 void dfs(Node* root,vector<int>&v,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        v.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(v);
        }
        dfs(root->left,v,ans);
        dfs(root->right,v,ans);
        v.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int>v;
        vector<vector<int>>ans;
        dfs(root,v,ans);
        return ans;
    }