class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = source.size();
        vector<long long> temp(n);
        for(int i=0; i<n; i++){
            temp[i]=1LL*source[i];
        }
        for(int i=0; i<n-1; i++){
            long long d = 1LL*temp[i] + 1LL*temp[i+1] - 1LL*target[i];
            temp[i] = target[i];
            temp[i+1] = d;
        }
        cout<<target[n-1]<<endl;
        if(target[n-1]==temp[n-1]){
            return 1;
        }
        return 0;
    }
};