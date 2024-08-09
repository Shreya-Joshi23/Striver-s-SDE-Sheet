
//REVERSE PREORDER TRAVERSAL
void solve(Node* root,int level,vector<int>&ans){
    if(root==NULL)return;
    if(ans.size()==level)ans.push_back(root->data);
    solve(root->left,level+1,ans);
    solve(root->right,level+1,ans);
    return;
}

//REVERSE POSTORDER TRAVERSAL
void rightview(Node* root,int level,vector<int>&res){
    if(root==NULL)return;
    if(ans.size()==level)res.push_back(root->data);
    solve(root->right,level+1,res);
    solve(root->left,level+1,res);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   solve(root,0,ans);
   return ans;
}