#include<bits/stdc++.h>
using namespace std;

bool isPossible(long long n, long long mid, long long w, long long h) {
    long long horizontal = mid / w;
    long long vertical = mid / h;

    // to avoid integer overflow
    if(horizontal == 0 || vertical == 0) return false;

    return horizontal >= (n + vertical - 1)/vertical;  // ceil value


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long w, h, n;
    cin>>w>>h>>n;

    // classic BS on Answer by Guessing
    long long low = 1;
    long long high = max(w, h)*1LL*n;
    long long ans = high;

    while(low <= high) {
        long long mid = low + (high - low)/2;

        if(isPossible(n, mid, w, h)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}