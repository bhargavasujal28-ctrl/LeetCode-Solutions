class Solution {
public:

    void dfs(unordered_map<int,vector<int>>& adj,vector<bool>& visited,int vertex){
        visited[vertex]=true;

        for(int neighbor:adj[vertex]){
            if(!visited[neighbor]){
                dfs(adj,visited,neighbor);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
        }

        return count;
    }
};