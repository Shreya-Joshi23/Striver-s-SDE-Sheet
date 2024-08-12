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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        //{node,{vrt,hz}}
        stack<pair<TreeNode*,pair<int,int>>>st;
        st.push({root,{0,0}});
        map< int,vector<pair<int,int>> >mp;

        while(!st.empty()){
            auto p=st.top();
            TreeNode* node=p.first;
            int vrt=p.second.first;
            int hz=p.second.second;
            mp[hz].push_back({vrt,node->val});
            st.pop();
            if(node->left)st.push({node->left,{vrt+1,hz-1}});
            if(node->right)st.push({node->right,{vrt+1,hz+1}});
        }

        auto cmp=[&](auto &p1,auto &p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }
            return p1.first<p2.first;
        };

        for(auto it:mp){
            vector<pair<int,int>> v=it.second;
            sort(v.begin(),v.end(),cmp);
            vector<int>s;
            for(auto it:v){
                s.push_back(it.second);
            }
            ans.push_back(s);
        }

        return ans;
    }
};