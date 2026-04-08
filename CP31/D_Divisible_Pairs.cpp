#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin>>t;

    while(t--) {
        long long n,x,y;
        cin>>n >>x >>y;

        vector<long long> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        long long pairs = 0;

        int i=0;
        int j = n-1;

        while(i < j) {
            if((a[i] + a[j]) % x == 0 && ((abs(a[i] - a[j])) % y == 0)) {
                pairs++;
                i++;
                j--;
            } else {
                j--;
            }
        }

        cout<<pairs<<endl;
    }

    return 0;

}