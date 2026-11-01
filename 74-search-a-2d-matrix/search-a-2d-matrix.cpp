class Solution {
public:
bool binarysearch(vector<vector<int>>& matrix,int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int s = 0;
    int e = n*m-1;
    while(s<=e){
        int mid = (s+e)/2;
        int col = mid%m;
        int row = (mid-col)/m;

        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]>target){
            e = mid-1;
        }
        else if(matrix[row][col]<target){
            s = mid+1;
        }
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
           if(binarysearch(matrix,target)){
            return true;
           }
        
        return false;
    }
};