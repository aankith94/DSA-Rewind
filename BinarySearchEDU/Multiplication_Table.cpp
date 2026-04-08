#include<bits/stdc++.h>
using namespace std;

bool chek(long long mid, long long n) {
    // we have to chek how many ele less than mid
    // we should chek row wise
    long long count_row = 0;
    for(long long i=1;i<=n;i++) {
        count_row += min(n, mid/i);
    }

    return count_row >= (n*n + 1)/2;
}

long long middleVal(long long n) {
    // BS on answer
    long long low = 1;
    long long high = n*n;
    long long ans = low;

    while(low <= high) {
        long long mid = low + (high - low)/2;

        if(chek(mid, n)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // n is odd
    long long n;
    cin>>n;

    cout<<middleVal(n)<<endl;

    return 0;
}