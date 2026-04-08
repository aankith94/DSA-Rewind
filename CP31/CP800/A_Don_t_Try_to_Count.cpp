#include<bits/stdc++.h>
using namespace std;

bool chekSubstring(string x, string s) {
    // chek s is present in x in a window
    if(s.size() > x.size()) {
        return false;
    }

    for(int i=0;i<x.size() - s.size() + 1;i++) {
        // chek in a window
        if(x.substr(i, s.size()) == s) {
            return true;
        }
    }
    return false;
}

int main() {
    long long t;
    cin>>t;

    while(t--) {
        long long n, m;
        cin>>n >> m;

        string x;
        cin>>x;
        string s;
        cin>>s;

        // code here!
        string x0 = x;
        string x1 = x0 + x0;
        string x2 = x1 + x1;
        string x3 = x2 + x2;
        string x4 = x3 + x3;
        string x5 = x4 + x4;  // 5 possible string

        long long ans = -1;
        if(chekSubstring(x0, s)) {
            ans = 0;
        } else if(chekSubstring(x1, s)) {
            ans = 1;
        } else if(chekSubstring(x2, s)) {
            ans = 2;
        } else if(chekSubstring(x3, s)) {
            ans = 3;
        } else if(chekSubstring(x4, s)) {
            ans = 4;
        } else if(chekSubstring(x5, s)) {
            ans = 5;
        }

        cout<<ans<<endl;
    }
}
