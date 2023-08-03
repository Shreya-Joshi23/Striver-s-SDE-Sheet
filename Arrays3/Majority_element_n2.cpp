class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using moore's algorithm
        //TC-O(n)
        //SC-O(1)
        
        int n=nums.size();
        int count=0;
        int ele=nums[0];

        for(int i=0;i<n;i++){
            if(count==0){
                ele=nums[i];
                count=1;
            }
            else if(ele==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }

        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                count++;
            }
        }

        return count>n/2?ele:-1;
    }
};