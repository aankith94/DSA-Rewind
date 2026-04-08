#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin>>t;

    int dx[4] = {1, -1, -1, 1};
    int dy[4] = {1, 1, -1, -1};

    while(t--) {
        long long a, b;
        cin>>a >>b;

        long long x_king, y_king;
        cin>>x_king>>y_king;

        long long x_queen, y_queen;
        cin>>x_queen>>y_queen;

        // soln
        // we have to do this in either O(logn) or O(1)
        set<pair<int, int>> king_hits, queen_hits;

        for(int j=0;j<4;j++) {
            king_hits.insert({x_king + dx[j]*a, y_king + dy[j]*b});
            king_hits.insert({x_king + dx[j]*b , y_king + dy[j]*a});  // 2 possible pos


            queen_hits.insert({x_queen + dx[j]*a, y_queen + dy[j]*b});
            queen_hits.insert({x_queen + dx[j]*b, y_queen + dy[j]*a});
        }

        // chek intersection
        long long ans = 0;
        for(auto pos : king_hits) {
            if(queen_hits.find(pos) != queen_hits.end()) {
                ans++;
            }
        }

        cout<<ans<<endl;

    }

    return 0;
}