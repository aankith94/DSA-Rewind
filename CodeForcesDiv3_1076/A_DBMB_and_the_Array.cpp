#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n, s, x;
        cin>>n >>s >>x;

        int sum = 0;

        for(int i=0;i<n;i++) {
            int y;
            cin>>y;

            sum += y;
        }

        if(sum > s) {
            cout<<"NO"<<endl;
        }

        else if((s - sum) % x == 0) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}