
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        //Morris Traversal
        //TC: O(n)
        //SC:O(1)

        TreeNode* curr=root;
        vector<int>result;

        while(curr!=NULL){
            if(curr->left==NULL){
                result.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* leftChild=curr->left;
                while(leftChild->right!=NULL && leftChild->right!=curr){
                    leftChild=leftChild->right;
                }
                
                //thread phle se exist nhi krti hai
                if(leftChild->right==NULL){
                    leftChild->right=curr;
                    curr=curr->left;
                }else{
                    leftChild->right=NULL;
                    result.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }

        return result;

    }
};