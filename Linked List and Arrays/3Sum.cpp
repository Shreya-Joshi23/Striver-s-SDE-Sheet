class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>>st;
        int n=nums.size();

        for(int i=0;i<n;i++){
            set<long long>hashset;
            for(int j=i+1;j<n;j++){
                int first=nums[i];
                int second=nums[j];
                long long third=0-(first+second);
                if(hashset.find(third)!=hashset.end()){
                    vector<int>temp={nums[i],nums[j],(int)third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert((long long)nums[j]);
            }
        }

        vector<vector<int>>ans(st.begin(),st.end());

        return ans;

    }
};