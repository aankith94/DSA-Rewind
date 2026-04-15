#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        ll ans = 0;

        for(int i=1;i<=100;i++) {
            if(n % i != 0){
                break;
            } else {
                ans++;
            }
        }

        cout<<ans<<endl;
    }
}