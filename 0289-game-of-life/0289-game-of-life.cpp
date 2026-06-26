class Solution {
public:
    int lives(int i, int j ,vector<vector<int>>& board ){
        int count=0;
        int n = board.size();
        int m = board[0].size();    

        // Originally alive cells are:
        // 1 (live → dead)
        // 3 (live → live)

        // Originally dead cells are:
        // 0
        // 2 , 0 -> 2 when its nearby states are live but originally it was still dead which we need to count not new state

        // So every check like board[i][j] == 1 || board[i][j] == 3
        //which is same as board[i][j]%2 == 1

        //RL
        if( j < m-1 && board[i][j+1]%2 == 1 ) count++;
        if( j > 0   && board[i][j-1]%2 == 1 ) count++;

        //TL-BR        
        if(i<n-1 && j<m-1 && board[i+1][j+1]%2 == 1 ) count++;
        if(i > 0 && j>0   && board[i-1][j-1]%2 == 1 ) count++;

        //TR-BL     
        if(i>0 && j<m-1 && board[i-1][j+1]%2 == 1 ) count++;
        if(j>0 && i<n-1 && board[i+1][j-1]%2 == 1 ) count++;

        //TB
        if(i>0   && board[i-1][j]%2 == 1 ) count++;
        if(i<n-1 && board[i+1][j]%2 == 1 ) count++;

        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        //initialization
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int check = lives(i,j,board);
                if( board[i][j] == 0){
                    if(check == 3)
                        board[i][j] = 2;
                }
                else{
                    if(check == 3 || check == 2)
                        board[i][j] = 3;
                }
            }
        }

        //changing back to live and dead
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( board[i][j] == 2 || board[i][j] == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};