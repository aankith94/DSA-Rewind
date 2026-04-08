#include<bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin>>T;

    while(T--) {
        int n;
        cin>>n;

        // we have to return the sum of digits
        // as n is 2 digit number
        int first = n % 10;
        int second = n / 10;

        int ans = first + second;

        cout<<ans<<endl;
    }

    return 0;
}