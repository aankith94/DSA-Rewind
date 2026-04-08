#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int n;
        cin>>n;  // n legs  only chichken and cow lives
        int ans = 0;

        // 2 config are diff if chicken != cow
        // we have to choose 2
        if(n % 2 != 0) ans = 0;// if odd no of legs
        else {
            ans = n/4 + 1;
        }
        cout<<ans<<endl;

    }
}