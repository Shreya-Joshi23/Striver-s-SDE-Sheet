class Solution
{
    public:
    
    static bool cmp(Item a,Item b){
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        
        double maxval=0;
        int curwt=0;
        
        for(int i=0;i<n;i++){
            if(curwt + arr[i].weight<=W){
                maxval+=arr[i].value;
                curwt+=arr[i].weight;
            }else{
                int remain=W-curwt;
                maxval+=(double)arr[i].value/(double)arr[i].weight*(double)remain;
                break;
            }
        }
        
        return maxval;
        
    }
        
};