class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        //sort
        sort(arr.begin(),arr.end());

        //set first element to 1
        arr[0] = 1;

        //change all elements so the abs diff is 1 
        for(int i=0;i<n-1;i++){
            if(arr[i+1] > arr[i]+1)
                arr[i+1] = arr[i]+1;
        }

        //last element is max
        return arr[n-1];
    }
};