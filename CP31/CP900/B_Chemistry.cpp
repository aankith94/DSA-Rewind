#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin>>t;

    while(t--) {
        long long n, k;
        cin>>n >>k;

        string s;
        cin>>s;

        unordered_map<char, int> mpp;

        int odd_count = 0;
        for(auto x : s) {
            mpp[x]++;
        }

        for(auto c : mpp) {
            if(c.second % 2 != 0) {
                odd_count++;
            }
        }

        if(odd_count > k+1) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }

    return 0;
}