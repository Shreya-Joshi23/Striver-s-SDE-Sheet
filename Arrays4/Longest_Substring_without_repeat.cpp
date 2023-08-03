class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int len=0;
        vector<int>charIndex(128,-1);
        int left=0;
        int right=0;

        while(right<n){
            if(charIndex[s[right]]>=left){
                left=charIndex[s[right]]+1;
            }
            charIndex[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};