class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int cnt = 1;
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        while((left<=right) && (top<=bottom)){
         int temp = left;
         while(temp<=right){
            res[top][temp]=cnt;
            cnt++;
            temp++;
         }
         top++;
         temp = top;
         while(temp<=bottom){
            res[temp][right]=cnt;
            cnt++;
            temp++;
         }
         right--;
         temp = right;
         while(temp>=left){
            res[bottom][temp]=cnt;
            cnt++;
            temp--;
         }
         bottom--;
         temp = bottom;
         while(temp>=top){
            res[temp][left]=cnt;
            cnt++;
            temp--;
         }
         left++;
        }
        return res;
    }
};