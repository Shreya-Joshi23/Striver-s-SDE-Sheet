class Solution 
{
    
    
    public:
    static bool comparison(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comparison);
        int max=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(arr[i].dead>max)
                max=arr[i].dead;
        }
        
        int slot[max+1];
        
        for(int i=0;i<=max;i++){
            slot[i]=-1;
        }
        
        int countjobs=0;
        int maxprofit=0;
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j]==-1){
                    slot[j]=i;
                    maxprofit+=arr[i].profit;
                    countjobs++;
                    break;
                }
            }
        }
        
        vector<int>ans;
        ans.push_back(countjobs);
        ans.push_back(maxprofit);
        
        return ans;
        
    } 
};