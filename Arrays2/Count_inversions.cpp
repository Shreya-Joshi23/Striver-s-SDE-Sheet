#include <bits/stdc++.h> 

int cnt=0;

void merge(long long *arr,int low,int mid,int high){
    int left=low;
    int right=high;
    vector<int>temp;

    while(low<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);        
            cnt+=(mid-left+1);
            right++;
        }
    }
    
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    
}

void mergeSort(long long *arr,int low,int high){
    if(low==high)return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

long long getInversions(long long *arr, int n){
    // Write your code here. 
    mergeSort(arr,0,n-1);
    return cnt;
}