class Solution {
public:
    int solve(int n , vector<int>& nums){
        int count = 0;
        for(auto i : nums)
            count += abs(n-i);
        return count;
    }
    int minMoves2(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums)
            sum+=i;
        
        int n = nums.size();
        int avg = sum/n;
        int count = INT_MAX;

        if(n <= 1) return 0;
        sort(nums.begin(),nums.end());

        if(n%2 == 0){
            count = solve(nums[n/2],nums);
        }
        else{
            count = solve(nums[(n-1)/2],nums);
        }

        return count;
    }
};