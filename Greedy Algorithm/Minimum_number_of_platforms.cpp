int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);

    int i=1;
    int j=0;
    int maxi=1;
    int count=1;

    while(j<n && i<n){
        if(at[i]<=dt[j]){
            count++;
            i++; 
        }else{
            count--;
            j++;
        }
        maxi=max(count,maxi);
    }

    return maxi;

}