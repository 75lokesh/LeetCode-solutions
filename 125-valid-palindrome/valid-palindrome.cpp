// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0;
//         int right = s.length() - 1;

//         while (left < right) {
//             while (left < right && !isalnum((unsigned char)s[left])) {
//                 left++;
//             }

//             while (left < right && !isalnum((unsigned char)s[right])) {
//                 right--;
//             }

//             if (tolower((unsigned char)s[left]) !=
//                 tolower((unsigned char)s[right])) {
//                 return false;
//             }

//             left++;
//             right--;
//         }

//         return true;
//     }
// };
class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        // Remove non-alphanumeric and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                temp += tolower(c);
            }
        }

        // Create reverse
        string rev = temp;
        reverse(rev.begin(), rev.end());

        // Compare
        return temp == rev;
    }
};