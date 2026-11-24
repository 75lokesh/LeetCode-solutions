class Solution {
   public:
    vector<vector<bool>> vis;
    bool solve(vector<vector<char>>& board, int x, int y, string &str, string& word) {
        if(str.size()>word.size()){
            return false;
        }
        if (str == word) {
            return true;
        }
        bool temp = false;
        if ((x > 0) && !vis[x - 1][y]) {
            str += board[x - 1][y];
            vis[x - 1][y]=1;
            temp = temp | solve(board, x - 1, y, str, word);
            str.pop_back();
            vis[x - 1][y]=0;
        }
        if ((x < board.size() - 1) && !vis[x + 1][y]) {
            str += board[x + 1][y];
            vis[x + 1][y] = 1;
            temp = temp | solve(board, x + 1, y, str, word);
            str.pop_back();
            vis[x + 1][y] = 0;
        }
        if ((y > 0) && !vis[x][y - 1]) {
            str += board[x][y - 1];
            vis[x][y - 1] = 1;
            temp = temp | solve(board, x, y - 1, str, word);
            str.pop_back();
            vis[x][y - 1] = 0;
        }
        if ((y < board[0].size() - 1) && !vis[x][y + 1]) {
            str += board[x][y + 1];
            vis[x][y + 1] = 1;
            temp = temp | solve(board, x, y + 1, str, word);
            str.pop_back();
            vis[x][y + 1] = 0;
        }
        return temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[n-1].size();
        vis.resize(n,vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    string str = "";
                    str+=word[0];
                    vis[i][j]=1;
                    if(solve(board, i, j, str, word)){
                        return true;
                    }
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};