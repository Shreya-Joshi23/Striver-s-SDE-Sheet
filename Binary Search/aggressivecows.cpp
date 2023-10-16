bool ispossible(vector<int>&stalls,int dist,int cows){
    int last=stalls[0];
    int cntcows=1;
    for(int i=0;i<stalls.size();i++){
        if((stalls[i]-last)>=dist){
            last=stalls[i];
            cntcows++;
        }
    }
    if(cntcows>=cows)return true;
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int cnt=0;
    for(int i=1;i<=(stalls[n-1]-stalls[0]);i++){
        if(ispossible(stalls,i,k)==true){
            cnt++;
            continue;
        }
        else break;
    }
    return cnt;
}