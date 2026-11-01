struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t seed = v.size();
        for (int i : v) {
            // Combine hash of each element
            seed ^= std::hash<int>()(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
class Solution {
public:
void permutations(vector<int> &nums, vector<bool>vis, int cnt , int n, unordered_set<vector<int>,VectorHash>&res, vector<int> temp){
    if(cnt == n){
        res.insert(temp);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<vector<int>,VectorHash> res;
        vector<int> temp;
        int n = nums.size();
        vector<bool> vis(n,0);
        int cnt = 0;
        permutations(nums,vis,cnt,n,res,temp);
        vector<vector<int>> ans;
        for(vector<int> it : res){
            ans.push_back(it);
        }
        return ans;
    }
};