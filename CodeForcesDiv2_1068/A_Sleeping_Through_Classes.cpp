#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        long long ans = 0;

        long long i = 0;
        while(i < n) {
            if(s[i] == '0') {
                ans++;
                i++;
            } else {
                i += (k+1);
            }
        }

        cout<<ans<<endl;
    }
}