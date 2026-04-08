#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        // logic
        int len = 0;
        // unordered_map<string, int> mpp;
        // for(auto x : s) {
        //     mpp[s]++;
        // }
        int zero = 0;
        int ones = 0;

        for(int i=0;i<s.size();i++) {
            if(s[i] == '0') zero++;
            else {
                ones++;
            }
        }

        for(int i=0;i<s.size();i++) {
            if(s[i] == '0' && ones > 0) {
                len++;
                ones--;
            }
            else if(s[i] == '1' && zero > 0) {
                len++;
                zero--;
            } else {
                break;
            }
        }

        cout<<s.size() - len<<endl;
    }

    return 0;
}