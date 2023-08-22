class Solution {
public:

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>ds;
        func(s,0,ds,ans);
        return ans;
    }

    void func(string s,int index,vector<string>&ds,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(palindrome(s,index,i)){
                ds.push_back(s.substr(index,i-index+1));
                fun(s,i+1,ds,ans);
                ds.pop_back();
            }
        }
    }

    bool palindrome(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};