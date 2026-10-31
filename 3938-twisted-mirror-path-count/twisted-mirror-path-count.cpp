class Solution {
public:

    int m;
    int n;
    int left=0;
    int up=1;
    int mod=1e9+7;

    int t[501][501][2];

    int solve(vector<vector<int>>& grid,int row,int col,int camefrom){
        if(row>=m || col>=n || row<0 || col<0){
            return 0;
        }
        if(row==m-1 && col==n-1){
            return 1;
        }

        if(t[row][col][camefrom]!=-1){
            return t[row][col][camefrom];
        }

        if(grid[row][col]==1){
            if(camefrom==left){
                return t[row][col][camefrom]=solve(grid,row+1,col,up);
            }
            else{
                return t[row][col][camefrom]=solve(grid,row,col+1,left);
            }
        }

        int totalcount=0;
        totalcount=(totalcount+solve(grid,row+1,col,up))%mod;
        totalcount=(totalcount+solve(grid,row,col+1,left))%mod;

        return t[row][col][camefrom]=totalcount;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));

        return solve(grid,0,0,left);
    }
};