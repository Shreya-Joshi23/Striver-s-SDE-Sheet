#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>>v;
    int n=start.size();
    for(int i=0;i<n;i++){
        v.push_back({finish[i],start[i]});
    }
    
    sort(v.begin(),v.end());

    int curmax=v[0].first;
    int count=1;

    for(int i=1;i<n;i++){
        if(curmax<=v[i].second){
            count++;
            curmax=v[i].first;
        }
    }

    return count;
}