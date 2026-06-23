class Solution {
public:
    long long check(int par , int cur, vector<vector<long long>>& adjL, vector<int>& bt){
        vector<long long>ans;
        long long curVal=0;
        long long earl = LLONG_MAX;
        long long lat = LLONG_MIN;
        for(auto i : adjL[cur]){
            if( i == par) continue;
            long long v = check(cur , i , adjL , bt );
            ans.push_back(v);
            earl = min(v,earl);
            lat = max(v,lat);
        }

        //this means its a lead node
        if(ans.empty()) return bt[cur];

        long long own = (lat-earl) + bt[cur];
        curVal = lat + own;

        return curVal;
    }
    long long finishTime(int n , vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<long long>>adjL(n);
        for(auto it : edges){
            long long u = it[0];
            long long v = it[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        return check(-1,0,adjL,baseTime);
    }
};