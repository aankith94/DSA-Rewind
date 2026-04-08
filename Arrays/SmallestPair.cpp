#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int N;
        cin>>N;
        
        int A[N];
        for(int i=0;i<N;i++) {
            cin>>A[i];
        }

        int res = 0;
        int ans = INT_MAX;

        for(int i=0;i<N;i++) {
            for(int j=i+1;j<N;j++) {
                res = A[i]+A[j]+ j-i;
                ans = min(ans, res);
            }
        }

        cout<<ans<<endl;

    }

    return 0;
}