// class Solution {
// public:
//     void Address(string s, vector<string>& res, string temp, string str,
//                  int index, int n, int dot) {

//         if (((stoi(temp) > 255) || (stoi(temp) == 0))) {
//             return;
//         }
//         if ((dot > 4)) {
//             return;
//         }
//         if ((stoi(temp) <= 255 && index == n)) {
//             res.push_back(str);
//         }
//         if (index >= n) {
//             return;
//         }
//         // take dot
//         temp += s[index];
       
//             str += '.' + s[index];
       
//         Address(s, res, temp, str, index + 1, n, dot + 1);
//         temp.pop_back();
//             str.pop_back();
//             str.pop_back();

//         // not take dot
//         temp += s[index];
//         str += s[index];
//         Address(s, res, temp, str, index, n, dot + 1);
//         temp.pop_back();
//         str.pop_back();
//         return;
//     }
//     vector<string> restoreIpAddresses(string s) {
//         vector<string> res;
//         int n = s.size();
//         string temp = "";
//         temp += s[0];
//         string str = "";
//         str += s[0];
//         Address(s, res, temp, str, 1, n, 0);
//         return res;
//     }
// };
class Solution {
public:
    void solve(string& s, vector<string>& res, string curr,
               int index, int dots) {

        if (dots == 4) {
            if (index == s.size()) {
                res.push_back(curr);
            }
            return;
        }

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {

            string temp = s.substr(index, len);

            // Leading zero is not allowed
            if (len > 1 && temp[0] == '0')
                break;

            int num = stoi(temp);

            if (num > 255)
                break;

            if (dots > 0)
                curr += ".";

            curr += temp;

            solve(s, res, curr, index + len, dots + 1);

            // Remove the current segment
            curr.resize(curr.size() - len);

            if (dots > 0)
                curr.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        if (s.size() < 4 || s.size() > 12)
            return res;

        solve(s, res, "", 0, 0);

        return res;
    }
};