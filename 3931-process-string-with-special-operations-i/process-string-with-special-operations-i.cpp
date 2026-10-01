class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string str = "";
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                if(str.size()>0){
                    str.pop_back();
                }
            }
           else if(s[i]=='#'){
                str = str + str;
            }
            else if(s[i]=='%'){
                reverse(str.begin(),str.end());
            }
            else{
                str += s[i];
            }
        }
        return str;
    }
};