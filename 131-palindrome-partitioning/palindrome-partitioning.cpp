class Solution {
   public:
    vector<vector<string>> res;
    bool ispalindrome(string str) {
        int left = 0;
        int right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string& s, int index, string str, vector<string>& temp) {
        if (index == s.size() && ispalindrome(str)) {
            temp.push_back(str);
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        if (index >= s.size()) {
            return;
        }
        if (!str.empty() && ispalindrome(str)) {
            temp.push_back(str);
            str = "";
            str += s[index];
            solve(s, index + 1, str, temp);
            str = temp[temp.size() - 1];
            temp.pop_back();
        }
        str += s[index];
        solve(s, index + 1, str, temp);
        str.pop_back();
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        string str = "";
        solve(s, 0, str, temp);
        return res;
    }
};
