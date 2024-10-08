class Solution {
public:

    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int lh=solve(root->left);
        int rh=solve(root->right);
        if(lh==-1 || rh==-1 || abs(lh-rh)>1)return -1;
        return max(lh,rh)+1;
    }

    bool isBalanced(TreeNode* root) {
        int ans=solve(root);
        if(ans==-1)return false;
        return true;
    }
};