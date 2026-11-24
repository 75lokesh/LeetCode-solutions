struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = 0;

        for (int x : v) {
            seed ^= std::hash<int>{}(x)
                    + 0x9e3779b9
                    + (seed << 6)
                    + (seed >> 2);
        }

        return seed;
    }
};

unordered_set<vector<int>, VectorHash> st;
class Solution {
   public:
    void solve(vector<int>& nums, int index, vector<int> temp, unordered_set<vector<int>, VectorHash>& st) {
        if (index >= nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            st.insert(temp);
            solve(nums, i + 1, temp, st);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        unordered_set<vector<int>,VectorHash> st;
        st.insert(vector<int>{});
        solve(nums, 0, {}, st);
        vector<vector<int>> ans;
        for(vector<int> it : st){
            ans.push_back(it);
        }
        return ans;
    }
};