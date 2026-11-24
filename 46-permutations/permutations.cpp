class Solution {
public:
void permutations(vector<int> &nums, vector<bool>vis, int cnt , int n, vector<vector<int>>&res, vector<int> temp){
    if(cnt == n){
        res.push_back(temp);
        return;
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            temp.push_back(nums[i]);
            vis[i]=1;
            permutations(nums,vis,cnt+1, n, res,temp);
            vis[i]=0;
            temp.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool>vis(n,0);
        int cnt = 0;
        permutations(nums,vis,cnt,n,res,temp);
        return res;
    }
};
