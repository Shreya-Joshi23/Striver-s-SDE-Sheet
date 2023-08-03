class Solution {
public:
    //Optimal Solution - 
    //Time complexity - 2*m*n
    //Space complexity - 1
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();     
        int n=matrix[0].size();
        // int row[m];  row=matrix[..][0]
        // int col[n];  col=matrix[0][..]
        int col0=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                   matrix[i][0]=0;
                   if(j!=0){
                   matrix[0][j]=0;
                   }
                   else{
                       col0=0;
                   }
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               if(matrix[i][j]!=0){
                   if(matrix[i][0]==0 || matrix[0][j]==0){
                       matrix[i][j]=0;
                   }
               }
            }
        }

        if(matrix[0][0]==0){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }

        if(col0 == 0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};