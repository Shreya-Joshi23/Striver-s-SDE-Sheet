vector<vector<int>>ans;
vector<int>inorder,preorder,postorder;

void solve(TreeNode* root){
   stack<pair<TreeNode*,int>>st;
   st.push({root,1});

   while(!st.empty()){
       auto p=st.top();
       TreeNode* node=p.first;
       st.pop();
       int cnt=p.second;
       if(cnt==1){
           preorder.push_back(node->data);
           st.push({node,cnt+1});
           if(node->left)st.push({node->left,1});
       }else if(cnt==2){
           inorder.push_back(node->data);
           st.push({node,cnt+2});
           if(node->right)st.push({node->right,1});
       }else{
           postorder.push_back(node->data);
       }
   }
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    solve(root);
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}