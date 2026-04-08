#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;

    long long ans = INT_MAX;
    for(int i=0;i<n;i++) {
        long long x;
        cin>>x;

        if(x < 0) x = -x;
        ans = min(ans, x);
    }

    cout<<ans<<endl;
}