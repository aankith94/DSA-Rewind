#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& boards, int maxTimeAllowed, int k) {
    // we have to write this chek function greedily
    int painter_used = 1;
    int current_sum = 0;

    for(int length : boards) {
        if(current_sum + length <= maxTimeAllowed) {
            current_sum += length;
        } else {
            current_sum = length;
            painter_used++;

            // chek for k
            if(painter_used > k) {
                return false;
            }
        }
    }

    return true;
}

int binarySearch(vector<int>& boards, int k) {
    // Definin the search Space
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low)/2;

        if(isPossible(boards, mid, k)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid +1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--) {
        int N, K;
        cin>>N>>K;

        vector<int> boards(N);
        for(int i=0;i<N;i++) {
            cin>>boards[i];
        }

        cout<<binarySearch(boards, K)<<endl;;
    }

    return 0;
}