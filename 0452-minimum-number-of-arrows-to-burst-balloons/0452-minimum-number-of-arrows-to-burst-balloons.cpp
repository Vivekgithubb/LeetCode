class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count = 0;
        for(int i=0; i<points.size();){
            int end = points[i][1];
            int j=i+1;
            while(j < points.size() && end >= points[j][0]){
                end = min(end ,points[j][1]);
                j++;
            }
            count++;
            i = j;
        }

        return count;
    }
};