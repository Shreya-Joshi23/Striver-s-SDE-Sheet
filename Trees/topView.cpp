vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>>q;
        vector<int>ans;
        map<int,int>mp;
        
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            Node* node=p.first;
            int hz=p.second;
            if(mp.find(hz)==mp.end()){
                mp[hz]=node->data;
            }
            if(node->left){
                q.push({node->left,hz-1});
            }
            if(node->right){
                q.push({node->right,hz+1});
            }
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }