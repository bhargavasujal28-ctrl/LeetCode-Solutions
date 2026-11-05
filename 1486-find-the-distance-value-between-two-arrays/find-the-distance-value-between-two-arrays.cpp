class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());

        int count=0;
        int n=arr2.size();

        for(int &x:arr1){
            int j=lower_bound(arr2.begin(),arr2.end(),x)-arr2.begin();
            if(j==0){       //all elements greater than euq to x;
                if(abs(x-arr2[0])>d) count++;
            }

            else if(j>=n){        //all elements in arr2 is smaller than x
                if(abs(x-arr2[n-1])>d)  count++;
            }

            else{
                if(abs(x-arr2[j])>d && abs(x-arr2[j-1])>d)  count++;
            }

        }

        return count;
    }
};