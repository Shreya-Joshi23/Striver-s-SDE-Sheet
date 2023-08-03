#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  //If array contains positive and zeroes
  
  int n=arr.size();
  
  int left=0;
  int right=0;
  int sum=arr[0];
  int k=0;
  int len=0;
  int longest=0;
  
  while(right<n){
    
    while(left<=right && sum>k){
      sum-=arr[left];
      left++;
    }
    
    if(sum==k){
      len=right-left+1;
      longest=max(longest,len);
    }
    
    right++;
    
    if(right<n) 
      sum+=arr[right];
    
  }

  return longest;
  
}