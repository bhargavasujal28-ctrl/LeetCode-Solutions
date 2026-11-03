class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max=*max_element(nums.begin(),nums.end());
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            count=count+(max-nums[i]);
        }

        return count;
    }
};