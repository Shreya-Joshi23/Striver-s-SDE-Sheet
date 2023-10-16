int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int xr=0;
    map<int,int>mp;
    int cnt=0;
    int n=a.size();

    for(int i=0;i<n;i++){
        xr=xr^a[i];
        int x=xr^b;
        cnt+=mp[x];
        mp[xr]++;
    }

    return cnt;

}