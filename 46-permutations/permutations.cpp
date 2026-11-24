class Solution {
public:
vector<vector<int>> res;
vector<bool> vis;
void solve(vector<int>&nums, vector<int> &temp){
    if(temp.size()==nums.size()){

        res.push_back(temp);
    }
    for(int i=0; i<nums.size(); i++){
        if(!vis[i]){
            temp.push_back(nums[i]);
            vis[i]=1;
            solve(nums,temp);
            temp.pop_back();
            vis[i]=0;
        }
    }
    return;
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vis.resize(n,0);
        vector<int> temp;
        solve(nums, temp);
        return res;
    }
};
