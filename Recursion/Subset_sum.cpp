void func(int idx,int sum,vector<int>num,int n,vector<int>&SumSubset){

	if(idx==n){
		SumSubset.push_back(sum);
		return;
	}

	func(idx+1,sum+num[idx],num,n,SumSubset);
	func(idx+1, sum, num, n, SumSubset);

}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int>SumSubset;
	int n=num.size();

	func(0,0,num,n,SumSubset);
	sort(SumSubset.begin(),SumSubset.end());

	return SumSubset;

}