
// USING STACK
class Solution
{
public:
    vector<int> preorder;

    void solve(TreeNode *node)
    {

        if (node == NULL)
            return;
        stack<TreeNode *> st;
        st.push(node);

        while (!st.empty())
        {
            auto n = st.top();
            preorder.push_back(n->val);
            st.pop();

            if (n->right)
            {
                st.push(n->right);
            }
            if (n->left)
            {
                st.push(n->left);
            }
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        solve(root);
        return preorder;
    }
};

// USING RECURSION
class Solution
{
public:
    vector<int> v;
    void pre(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        v.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        pre(root);
        return v;
    }
};