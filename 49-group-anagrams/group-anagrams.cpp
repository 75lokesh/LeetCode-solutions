class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({strs[i], i});
        }
        for (int i = 0; i < n; i++) {
            sort(temp[i].first.begin(), temp[i].first.end());
        }
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < n; i++) {
            cout<<temp[i].first<<endl;
            m[temp[i].first].push_back(strs[temp[i].second]);
        }
        vector<vector<string>> ans;
        for (auto it : m) {
            vector<string> temp2;
            for (auto it1 : it.second) {
                temp2.push_back(it1);
            }
            ans.push_back(temp2);
        }
        return ans;
    }
};