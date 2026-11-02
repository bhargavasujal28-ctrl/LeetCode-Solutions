//Approach-1 (O(NlogN)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int mid=nums[n/2];
        int ans=0;

        for(int i=0;i<n;i++){
            ans=ans+abs(mid-nums[i]);
        }

        return ans;
    }
};



//Approach-2 (optimised to O(N)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int mid=nums[n/2];
        int ans=0;

        for(int i=0;i<n;i++){
            ans=ans+abs(mid-nums[i]);
        }

        return ans;
    }
};
