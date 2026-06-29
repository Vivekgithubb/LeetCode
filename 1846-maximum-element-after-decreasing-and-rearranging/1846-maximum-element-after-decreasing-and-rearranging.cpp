class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        //sort
        // sort(arr.begin(),arr.end());

        // //set first element to 1
        // arr[0] = 1;

        // //change all elements so the abs diff is 1 
        // for(int i=0;i<n-1;i++){
        //     if(arr[i+1] > arr[i]+1)
        //         arr[i+1] = arr[i]+1;
        // }

        // //last element is max
        // return arr[n-1];

        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            freq[min(arr[i],n)]++;
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            if(freq[i] == 0) continue;
            ans = min(ans+freq[i] , i);
        }

        return ans;
    }
};