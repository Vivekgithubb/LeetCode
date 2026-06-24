class Solution {
public:
    int maxDistance(string moves) {
        int x=0;
        int y=0;
        int u=0;
       for(auto m : moves){
            if( m == 'L'){
                x--;
            }
            else if( m=='D'){
                y--;
            }
            else if( m=='R'){
                x++;
            }
            else if( m =='U'){
                y++;
            }
            else 
                u += 1;
        } 
        return abs(x) + abs(y) + u;;
    }
};