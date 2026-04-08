#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        string s, t;
        cin>>s>>t;
        

        int ptr = 0;

        // check if t is a subsequence or not
        for(int i=0;i<s.size();i++) {
            if(s[i] == '?') {
                if(ptr < t.size()) s[i] = t[ptr];
                else {
                    s[i] = 'a';
                }
            }
            if(ptr < t.size() && s[i] == t[ptr]) {
                ptr++;
            }
        }

        if(ptr < t.size()) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl<< s <<endl;
        }
    }
}