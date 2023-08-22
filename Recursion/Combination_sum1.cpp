class Solution {

private:
void combinations(int idx,int target,vector<int>&ds,vector<vector<int>>&ans,vector<int>& candidates){
    //Base Case

    if(idx==candidates.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }

    if(candidates[idx]<=target){
    ds.push_back(candidates[idx]);
    combinations(idx,target-candidates[idx],ds,ans,candidates);
    ds.pop_back();
    }
    combinations(idx+1,target,ds,ans,candidates);
}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        combinations(0,target,ds,ans,candidates);
        return ans;
    }
};