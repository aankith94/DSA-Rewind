#include<bits/stdc++.h>
using namespace std;

int main() {
    long long T;
    cin>>T;

    while(T--) {
        long long n, k;
        cin>> n >> k;

        vector<long long> a(n);
        vector<long long> b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        for(int i=0;i<n;i++) {
            cin>>b[i];
        }

        // code here!
        long long sum = 0;

        for(int i=0;i<n;i++) {
            sum += a[i];
        }
        
    }
}