vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int>ans;
    vector<int>den = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int s=9;

    for(int i=s-1;i>=0;i--){
        while(n>=den[i]){
            n=n-den[i];
            ans.push_back(den[i]);
        }
    }

    return ans;
}