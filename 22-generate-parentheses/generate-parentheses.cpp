class Solution {
   public:
    vector<string> res;
    bool verify(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
    void solve(int size, string str, int open, int close) {
        if (str.size() == size && verify(str)) {
            res.push_back(str);
        }
        if (open != 0) {
            str.push_back('(');
            solve(size, str, open - 1, close);
            str.pop_back();
        }
        if (close != 0) {
            str.push_back(')');
            solve(size, str, open, close - 1);
            str.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(2 * n, "", n, n);
        return res;
    }
};