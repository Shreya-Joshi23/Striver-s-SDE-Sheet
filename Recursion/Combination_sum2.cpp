class Solution {

private:
void combinations(int idx,int target,vector<int>&ds,vector<vector<int>>&ans,vector<int>& candidates){

    if(target==0){
        ans.push_back(ds);
        return;
    }

    for(int i=idx;i<candidates.size();i++){
        if(i>idx && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
        ds.push_back(candidates[i]);
        combinations(i+1,target-candidates[i],ds,ans,candidates);
        ds.pop_back();
    }
}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        combinations(0,target,ds,ans,candidates);
        return ans;
    }
};