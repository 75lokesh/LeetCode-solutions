class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
     if(abs(source[0]-target[0]) == abs(source[1]-target[1]) && source[0]!=target[0]){
         return 1;
     }
        else if(source[0]!=target[0] && source[1]==target[1]){
            return 1;
        }
        else if(source[0]==target[0] && source[1]!=target[1]){
            return 1;
        }
        else if(source[0]!=target[0] && source[1]!=target[1]){
            return 2;
        }
        return 0;
    }
};