//approach 1-brute force traversing both the arrays:O(N2)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        for(int i=0;i<arr1.size();i++){
            bool allhigher=true;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    allhigher=false;
                    break;
                }
            }

            if(allhigher==true){
                count++;
            }
        }

        return count;
    }
};

/*Aproach 2 where optimised the code to o(nlogn)    
    where i first sorted the array2 then used lower bound to find the first element greater than or equal to arr1's element then 
    checked for the condition that the difference between the arr1 value and lower bound value is gretaer than d value and 
    lowerbound-1 value is greater than d    */
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
