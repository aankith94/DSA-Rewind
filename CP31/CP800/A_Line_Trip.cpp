#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        long long n, x;
        cin>> n >> x;  // input

        vector<long long> a(n);

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        // code here!
        // 0 and x pe koi gas station nahi hai
        long long minVolume = 0;
        for(int i=1;i<n;i++) {
            long long diff = a[i] - a[i-1];
            minVolume = max(diff, minVolume);
        }

        long long start = a[0];
        long long last = 2 * abs(a[n-1] - x);
        long long ans = max(start, last);

        minVolume = max(minVolume, ans);

        cout<<minVolume<<endl;
    }
}