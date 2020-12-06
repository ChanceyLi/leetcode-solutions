class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int numX = 0, numO = 0;
        for(auto s : board) 
            for(int i = 0; i < 3; ++i) {
                numX += s[i] == 'X';
                numO += s[i] == 'O';
            }
        if(numX > numO + 1 || numX < numO)//数量限定
            return false;
        vector<char> str(8,' ');//8个可能相连方式
        for(int i = 0; i < 3; ++i) {
            str[i] = board[i][0] == board[i][1] && board[i][0] == board[i][2] ? board[i][0] : ' ';//横三
            str[i+3] = board[0][i] == board[1][i] && board[0][i] == board[2][i] ? board[0][i] : ' ';//竖三
        }
        str[6] = board[0][0] == board[1][1] && board[0][0] == board[2][2] ? board[0][0] : ' ';//右下
        str[7] = board[0][2] == board[1][1] && board[0][2] == board[2][0] ? board[0][2] : ' ';//右上
        int count = 0; vector<char> c(2);//c表示相连的子的类型
        for(int i = 0; i < 8; ++i) {
            if(str[i] != ' ') {
                c[count] = str[i];
                ++count;
            }
        }
        if(count > 2) return false;//不可能出现三个及以上的相连
        if(count == 2 && (c[0] != c[1] || c[0] != 'X'))//易错！["XXX","OOX","OOX"]可以出现
            return false; 
        if(count == 1) {
            if(c[0] == 'X' && numX == numO) 
                return false;
            if(c[0] == 'O' && numX == numO + 1)
                return false;   
        }
        return true;   
    }
};
