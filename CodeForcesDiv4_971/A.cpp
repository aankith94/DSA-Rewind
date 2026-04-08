#include<bits/stdc++.h>
using namespace std;

int main() {
    // we have to find min((c-a) + (b-c))
    int T;
    cin>>T;

    while(T--) {
        int a, b;
        cin>>a >>b;

        // result
        int ans = b - a;

        cout<<ans<<endl;
    } 

    return 0;
}