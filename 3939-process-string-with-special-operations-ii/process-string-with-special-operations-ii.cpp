// class Solution {
// public:
//     char processStr(string s, long long k) {
//         long long n = s.size();
//         string str = "";
//         int i = 0;
//         while (i < n) {
//             if (s[i] == '*') {
//                 if (1LL * str.size() > 0) {
//                     str.pop_back();
//                 }
//                 i++;
//             } else if (s[i] == '#') {
//                 str += str;
//                 i++;
//             } else if (s[i] == '%') {
//                 int cnt = 0;
//                 while ((i < n) && (s[i] == '%')) {
//                     cnt++;
//                     i++;
//                 }
//                 if (cnt % 2 != 0) {
//                     reverse(str.begin(), str.end());
//                 }
//             } else {
//                 str += s[i];
//                 i++;
//             }
//         }
//         if (k < 1LL * str.size()) {
//             int temp = (signed int)(k);
//             return str[temp];
//         }
//         return '.';
//     }
// };
class Solution {
public:
    char processStr(string s, long long k) {

        long long len = 0;

        // 1. Find final length
        for (char c : s) {

            if (c >= 'a' && c <= 'z') {
                len++;
            }
            else if (c == '*') {
                len = max(0LL, len - 1);
            }
            else if (c == '#') {
                len *= 2;
            }
            // '%' does not change length
        }

        // k is 0-indexed
        if (k >= len)
            return '.';

        // 2. Trace kth position backwards
        for (int i = s.size() - 1; i >= 0; i--) {

            char c = s[i];

            if (c == '*') {

                // Forward:
                // A + x -> A
                //
                // Going backwards, restore x.
                len++;

            }
            else if (c == '#') {

                // Forward:
                // A -> A + A
                //
                // Previous length
                len /= 2;

                // If k was in the second copy,
                // map it to the corresponding position
                // in the first copy.
                if (k >= len)
                    k -= len;

            }
            else if (c == '%') {

                // Forward:
                // A -> reverse(A)
                //
                // kth position in reverse(A)
                // corresponds to (len - 1 - k)
                k = len - 1 - k;

            }
            else {

                // Forward:
                // A -> A + c
                //
                // c is at the last position.
                len--;

                if (k == len)
                    return c;
            }
        }

        return '.';
    }
};