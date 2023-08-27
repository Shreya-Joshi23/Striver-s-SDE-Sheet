class Solution {

    private:
    void helper(int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&lowerDiag,vector<int>&upperDiag,vector<int>&leftRow,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerDiag[row+col]==0 && upperDiag[(n-1)+(col-row)]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiag[row+col]=1;
                upperDiag[(n-1)+(col-row)]=1;
                helper(col+1,ans,board,lowerDiag,upperDiag,leftRow,n);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiag[row+col]=0;
                upperDiag[(n-1)+(col-row)]=0;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,"");
        string s(n,'.');

        for(int i=0;i<n;i++){
            board[i]=s;
        }

        vector<int>lowerDiag(2*n-1,0);
        vector<int>upperDiag(2*n-1,0);
        vector<int>leftRow(n,0);
        helper(0,ans,board,lowerDiag,upperDiag,leftRow,n);
        return ans;
    }
};