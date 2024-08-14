class Solution {
public:

   bool findPath(TreeNode* root, TreeNode* p, std::vector<TreeNode*>& path) {
    if (root == nullptr) {
        return false;
    }
    path.push_back(root);
    if (root->val == p->val) {
        return true;
    }

    if(findPath(root->left, p, path) || findPath(root->right, p, path))return true;

    path.pop_back();
    return false;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //store path of p and q in two different vectors
        if(root==NULL)return NULL;
        vector<TreeNode*>ppath,qpath;
        if(findPath(root,p,ppath)==false || findPath(root,q,qpath)==false)return nullptr;

        for(int i=0;i<ppath.size();i++){
            cout<<ppath[i]->val<<" ";
        }
        for(int i=0;i<qpath.size();i++){
            cout<<qpath[i]->val<<" ";
        }
        int n=ppath.size(),m=qpath.size();
        int i=0,j=0;
        while(i<n && j<m && ppath[i]->val==qpath[j]->val){
            i++;j++;
        }

        return ppath[i-1];
    }
};