class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans=0;
        //1.sort in descending
        sort(nums.rbegin(),nums.rend());   

        //2.select k largest elements and apply operation
        int i=0;
        while(i<k){
            if(mul > 0)
                ans += 1LL*mul*nums[i];
            else
                ans += 1LL*nums[i];
            i++;
            mul--;
        }

        return ans;

    }
};