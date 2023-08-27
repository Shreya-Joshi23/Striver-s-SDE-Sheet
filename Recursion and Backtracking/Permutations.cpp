class Solution {
public:

    void f(vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums,int vis[]){
        int n=nums.size();
        if(ds.size()==n){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                ds.push_back(nums[i]);
                f(ds,ans,nums,vis);
                ds.pop_back();
                vis[i]=0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        int vis[n];

        for(int i=0;i<n;i++)vis[i]=0;
        f(ds,ans,nums,vis);

        return ans;

    }
};