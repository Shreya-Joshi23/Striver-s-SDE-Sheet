class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());

        int left=0;
        int right=n-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==target){
                ans.push_back(left);
                ans.push_back(right);
            }else if(ele>target){
                right--;
            }else{
                left++;
            }
        }
        return ans;
    }
};