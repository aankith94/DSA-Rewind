#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        vector<string> arr(10);

        for(int i=0;i<10;i++) {
            cin>>arr[i];
        }

        long long ans = 0;
        long long points = 0;
        
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                if(arr[i][j] == 'X') {
                    
                    int ring = min({i, j, (9-i), (9-j)});
                    points = ring +1;

                    ans = ans + points;

                }
            }
        }
        
        cout<<ans<<endl;
    }
}