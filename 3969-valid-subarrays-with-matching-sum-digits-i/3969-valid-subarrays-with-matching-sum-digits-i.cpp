class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            long long sum = 0;   
            for(int j=i;j<nums.size();j++){
                sum += 1LL*nums[j];
                long long l = sum%10;
                long long r = 0;

                long long curSum = sum;
                while(curSum > 0){
                    r = curSum %10;
                    curSum /= 10;
                }

                if( (l == x) && (r == x) )
                    count++;
            }
        }

        return count;
    }
};