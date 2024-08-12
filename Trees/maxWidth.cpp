/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});

        unsigned long long maxi=1;

        while(!q.empty()){
            unsigned long long qsize=q.size();
            unsigned long long firstidx=q.front().second;
            unsigned long long lastidx=q.back().second;
            maxi=max(maxi,lastidx-firstidx+1);
            while(qsize--){
                auto p=q.front();
                TreeNode* node=p.first;
                unsigned long long idx=p.second;
                q.pop();
                if(node->left)q.push({node->left,2LL*idx});
                if(node->right)q.push({node->right,2LL*idx+1});
            }
        }

        return maxi;

    }
};