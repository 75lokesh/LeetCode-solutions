class Solution {
public:
    void solve(string s, int index, int n, vector<string>& res,
               unordered_map<string, int>& m, string temp, string str) {
        if (index >= n) {
            if (((m.find(temp) != m.end()) && (temp.size() != 0))) {
                    if (str.size() != 0) {
                        res.push_back(str + " " + temp);
                    } else {
                        res.push_back(temp);
                    }
                }
            return;
        }
        if ((m.find(temp) != m.end()) && (temp.size() != 0)) {
            string temp1 = temp;
            if (str.size() != 0) {
                str += " ";
            }
            str += temp;
            temp = "";
            solve(s, index + 1, n, res, m, temp + s[index], str);
            temp = temp1;
            str.erase(str.size() - temp.size());
            if (str.size() != 0) {
                str.pop_back();
            }
        }
        solve(s, index + 1, n, res, m, temp + s[index], str);
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_map<string, int> m;
        int n = wordDict.size();
        int n1 = s.size();
        for (string str : wordDict) {
            m[str]++;
        }

        solve(s, 0, n1, res, m, "", "");
        return res;
    }
};