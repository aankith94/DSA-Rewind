#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        long long x, y, k;
        cin >> x >> y >> k;

        int A = (x+k-1)/k;
        int B = (y+k-1)/k;

        if (A <= B) {
            cout<<2*B<<endl;
        }
        else {
            cout<<2*A - 1<<endl;
        }

    }
    return 0;
}
