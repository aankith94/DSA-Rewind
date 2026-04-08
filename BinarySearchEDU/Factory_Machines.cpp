#include<bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int>& time, long long mid, long long t) {
    long long items = 0;
    for(int x : time) {
        items += mid / x;
        if(items >= t) return true;
    }
    return false;
}

long long time_to_make(const vector<int>& time, long long t) {
    long long low = 1;
    long long high = (*min_element(time.begin(), time.end())) * t;
    long long ans = high;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(isPossible(time, mid, t)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, t;
    cin >> n >> t;

    vector<int> time(n);
    for(int i = 0; i < n; i++) cin >> time[i];

    cout << time_to_make(time, t) << '\n';
    return 0;
}
