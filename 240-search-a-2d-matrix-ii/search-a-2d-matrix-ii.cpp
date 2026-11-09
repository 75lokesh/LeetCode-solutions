class Solution {
public:
bool BinarySearch(vector<vector<int>>& matrix, int row, int target){
    int s = 0;
    int e = matrix[row].size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(matrix[row][mid]==target){
            return true;
        }
        else if(matrix[row][mid]>target){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            if(BinarySearch(matrix,i,target)){
                return true;
            }
        }
        return false;
    }
};