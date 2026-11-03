class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int left=0,maxlen=0;
        int n = s.size();
        for(int right=0;right<n;right++){
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};