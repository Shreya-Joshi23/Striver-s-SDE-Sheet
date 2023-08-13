class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int profit;
       int max_profit=0;

       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
               profit=prices[j]-prices[i];
               max_profit=max(max_profit,profit);
           }
       }

       if(max_profit>0)return max_profit;
       return 0;
    }
};