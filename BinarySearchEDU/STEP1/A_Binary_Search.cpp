#include<bits/stdc++.h>
using namespace std;

bool isOccur(vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low)/2;

        if(arr[mid] == x) {
            return true;
        } else if(x > arr[mid]) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return false;  // at last
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;  // len of array and no of queries

    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    // chek for each queries
    while(k--) {
        int x;
        cin>>x;

        bool found = isOccur(arr, x);

        cout<<(found ? "YES" : "NO")<<endl;
    }

    return 0;
}

// TC = O(K*LOG(N))