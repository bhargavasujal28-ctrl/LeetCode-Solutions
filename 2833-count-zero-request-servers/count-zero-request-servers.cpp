class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();

        auto lambda=[](vector<int>& a,vector<int> b){
            return a[1]<b[1];
        };
        sort(logs.begin(),logs.end(),lambda);   //sort logs based on time which is the second index

        int q=queries.size();
        vector<int> result(q);

        vector<pair<int,int>> timeindex(q); //took an additional array in which i took time according to the index as final result looks for the answer in accordance to the input and we wanted the sorted time of queries as well and timeindex first index stores the time and second index stores the original index


        for(int i=0;i<q;i++){
            timeindex[i].first=queries[i];
            timeindex[i].second=i;
        }

        sort(timeindex.begin(),timeindex.end());

        unordered_map<int,int> mp;      //stores the server and its count in the range asked in the query as queries[i]-x and queries

        int i=0;int j=0;
        for(auto& [time,idx]:timeindex){
            int start=time-x;
            int end=time;

                //expansion

            while(j<m && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }

                //shrinking
                
            while(i<m && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }

            result[idx]=n-mp.size();    //final result stored in its correct input posiiton as n is the total number of servers and mp.size() is the total number of servers which receive zero requests as they fall in the range of queries[0]-x,queries[0]
        }

        return result;
    }
};