class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        int n1 = version1.size();
        int index = 0;
        string str = "";
        while (index < n1) {
            if (version1[index] == '.') {
                v1.push_back(stoi(str));
                str = "";
            } else {
                str += version1[index];
            }
            index++;
        }
        v1.push_back(stoi(str));
        str = "";
        int n2 = version2.size();
        index = 0;
        while (index < n2) {
            if (version2[index] == '.') {
                v2.push_back(stoi(str));
                str = "";
            } else {
                str += version2[index];
            }
            index++;
        }
        v2.push_back(stoi(str));
        int n4 = v2.size();
        int n3 = v1.size();

        for (int i = 0; i < min(n3, n4); i++) {
            cout << v1[i] << " " << v2[i] << endl;
            if (v1[i] < v2[i]) {
                cout<<"u"<<endl;
                return -1;
            } else if (v1[i] > v2[i]) {
                return 1;
            }
        }
        if (n3 > n4) {
            int cnt = 0;
            for (int i = n4; i < n3; i++) {
                if (v1[i] == 0) {
                    cnt++;
                }
            }
            if (cnt == n3 - n4) {
                return 0;
            } else
                return 1;
        } else if (n4 > n3) {
            int cnt = 0;
            for (int i = n3; i < n4; i++) {
                if (v2[i] == 0) {
                    cnt++;
                }
            }
            if (cnt == n4 - n3) {
                return 0;
            } else {
                return -1;
            }
        }
        return 0;
    }
};