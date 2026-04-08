#include<bits/stdc++.h>
using namespace std;

bool chek(long long mid, long long n, long long x, long long y) {
    if(mid < min(x, y)) return false;

    long long copies = 1; // first copy by faster copier
    long long remaining = mid - min(x, y);

    copies += remaining / x;
    copies += remaining / y;

    return copies >= n;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x, y;
    cin>>n>>x>>y;

    // classic BS on Answer
    long long low = 1;
    long long high = max(x, y)*n;
    
    long long ans = high;

    while(low <= high) {
        long long mid = low + (high - low)/2;

        if(chek(mid, n, x, y)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}