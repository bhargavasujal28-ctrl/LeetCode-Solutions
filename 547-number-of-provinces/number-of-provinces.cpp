
//use the isconnected as it is as it is itself indicating a graph no need to generate the graph manually here 

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

//generated manual graph

class Solution {
public:

    void dfs(unordered_map<int,vector<int>>& adj,vector<bool>& visited,int vertex){
        visited[vertex]=true;

        for(int &neighbor:adj[vertex]){
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
