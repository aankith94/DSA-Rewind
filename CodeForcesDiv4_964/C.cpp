#include<bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin>>T;

    while(T--) {
        int n, s, m;
        cin>>n>>s>>m;

        vector<pair<long long, long long>> tasks;
        for(int i=0;i<n;i++) {
            int l, r;
            cin>>l>>r;
            tasks.push_back({l, r});
        }

        tasks.push_back({0, 0});
        tasks.push_back({m, m});

        // now sort the task
        sort(tasks.begin(), tasks.end());
        bool ans = false;

        for(int i=1;i<tasks.size();i++) {
            if(tasks[i-1].second + s <= tasks[i].first) {
                ans = true;
                break;
            }
        }

        if(ans) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

        
    }

    return 0;
}

