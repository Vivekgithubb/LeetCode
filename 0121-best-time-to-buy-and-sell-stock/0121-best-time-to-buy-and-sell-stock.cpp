class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX;
        int maxP = INT_MIN;
        for(auto i : prices){
            minP = min(i,minP);
            maxP = max(maxP , i-minP);
        }
        return maxP;
    }
};