class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnta = 0;
        int cntb = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                cnta++;
            }
            else{
                cntb++;
            }
        }
        return abs(cnta-cntb);
    }
};