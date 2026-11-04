class Solution {
public:
    int n;

    void dfs(vector<vector<int>>& isConnected,vector<bool>& visited,int vertex){
        visited[vertex]=true;

        for(int neighbor=0;neighbor<n;neighbor++){
            if(!visited[neighbor] && isConnected[vertex][neighbor]==1){
                dfs(isConnected,visited,neighbor);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();


        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                count++;
            }
        }

        return count;
    }
};