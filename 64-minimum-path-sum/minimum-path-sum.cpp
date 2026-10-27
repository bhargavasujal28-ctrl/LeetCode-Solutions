class Solution {
public:
    int m,n;
    int t[201][201];

    int solve(int row,int col,int m,int n,vector<vector<int>>& grid){
        if(row==m-1 && col==n-1){   //go only right
            return grid[row][col];
        }
        if(t[row][col]!=-1){
            return t[row][col];
        }

        if(row==m-1){
            return t[row][col]=grid[row][col]+solve(row,col+1,m,n,grid);
        }
        else if(col==n-1){
            return t[row][col]=grid[row][col]+solve(row+1,col,m,n,grid);
        }
        else{
            return t[row][col]=grid[row][col]+min(solve(row+1,col,m,n,grid),solve(row,col+1,m,n,grid));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));

        return solve(0,0,m,n,grid);
    }
};