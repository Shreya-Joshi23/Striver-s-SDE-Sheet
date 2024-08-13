class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=1;
        int rh=1;
        if(root->left)lh=1+maxDepth(root->left);
        if(root->right)rh=1+maxDepth(root->right);
        return max(lh,rh);
    }
};