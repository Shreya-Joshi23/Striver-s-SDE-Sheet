class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Time Complexity-O(n)+O(2n)=O(3n)
        //Space complexity-O(n)
        unordered_set<int>st;
        int longest=1;
        int cnt=0;
        int n=nums.size();

        if(n==0)return 0;

        for(int i=0;i<n;i++){   //O(n)
            st.insert(nums[i]);
        }

        for(auto it:nums){  //O(2n)
            if(st.find(it-1)==st.end()){
                //means its the first element
                //In this approach we are not starting from between we are calculating the count by first element
                cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;
                }
            }
            longest=max(longest,cnt);
        }

        return longest;
    }
};