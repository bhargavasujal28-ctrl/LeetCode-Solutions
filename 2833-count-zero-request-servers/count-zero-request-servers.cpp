class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();

        auto lambda=[](vector<int>& a,vector<int> b){
            return a[1]<b[1];
        };
        sort(logs.begin(),logs.end(),lambda);

        int q=queries.size();
        vector<int> result(q);

        vector<pair<int,int>> timeindex(q);
        for(int i=0;i<q;i++){
            timeindex[i].first=queries[i];
            timeindex[i].second=i;
        }

        sort(timeindex.begin(),timeindex.end());

        unordered_map<int,int> mp;

        int i=0;int j=0;
        for(auto& [time,idx]:timeindex){
            int start=time-x;
            int end=time;

            while(j<m && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }

            while(i<m && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }

            result[idx]=n-mp.size();
        }

        return result;
    }
};