class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //Optimal Approach
        
        int n=matrix.size();
        int m=matrix[0].size();

        int lb=0;
        int ub=(n*m)-1;

        while(lb<=ub){

            int mid=lb+(ub-lb)/2;

            if(matrix[mid/m][mid%m]==target){
                return true;
            }

            if(matrix[mid/m][mid%m]<target){
                lb=mid+1;
            }
            else{
                ub=mid-1;
            }

        }

        return false;
    }
};