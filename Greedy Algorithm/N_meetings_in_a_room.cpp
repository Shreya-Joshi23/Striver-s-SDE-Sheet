int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<int,int>>v;
    int n=start.size();

    for(int i=0;i<n;i++){
        v.push_back({end[i],start[i]});
    }

    sort(v.begin(),v.end());
    int count=1;
    int curmax=v[0].first;

    for(int i=1;i<n;i++){
        if(curmax<v[i].second){
            count++;
            curmax=v[i].first;
        }
    }

    return count;

}