#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xr=0;
	
	for(int i=0;i<n;i++){
		xr=xr^arr[i];
		xr=xr^(i+1);
	}

	int bitNo=0;
	while(1){
		if((xr & (1<<bitNo))!=0){
			break;
		}
		bitNo++;
	}

	int zero=0;
	int one=0;

	for(int i=0;i<n;i++){
		if((arr[i] & (1<<bitNo))!=0){
			one=one^arr[i];
		}
		else{
			zero=zero^arr[i];
		}
	}

	for(int i=1;i<=n;i++){
		//part of one club
		if((i & (1<<bitNo))!=0){
			one=one^i;
		}
		
		//part of zero club
		else{
			zero=zero^i;
		}
	}

	int cnt=0;
	for(int i=0;i<n;i++){
		if(arr[i]==zero){
			cnt++;
		}
	}

	if(cnt==2)
		return {one,zero};
	
	return {zero,one};
}
