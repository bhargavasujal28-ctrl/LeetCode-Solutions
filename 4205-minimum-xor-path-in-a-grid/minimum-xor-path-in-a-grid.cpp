class Solution {
public:
    int m,n;
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<unordered_set<int>>> dp(m,vector<unordered_set<int>>(n));

        dp[0][0].insert(grid[0][0]);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                int val=grid[i][j];

                if(i>0){        //answers from above
                    for(int x:dp[i-1][j]){
                        dp[i][j].insert(x^val);
                    }
                }

                if(j>0){        //answers/path coming from left
                    for(int x:dp[i][j-1]){
                        dp[i][j].insert(x^val);
                    }
                }
            }
        }
        return *min_element(dp[m-1][n-1].begin(),dp[m-1][n-1].end());
    }
};