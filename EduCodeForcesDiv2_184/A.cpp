// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int T;
//     cin>>T;

//     while(T--) {
//         long long n, a;
//         cin>>n>> a;   // number of marbles  and  no chosen by alice

//         vector<long long> marbles(n);
//         for(int i=0;i<n;i++) {
//             cin>>marbles[i];
//         }

//         // we have to output b
//         // bob's can maximize the no of points he receive

//         sort(marbles.begin(), marbles.end());

//         // int low = 0;
//         // int high = n-1;
//         // int half = n/2;
//         // int pos = -1;


//         int cnt1 = 0;
//         int cnt2 = 0;
//         // while(low <= high) {
//         //     int mid = low + (high - low)/2;

//         //     if(marbles[mid] > a ) {
//         //         high = mid-1;
//         //         pos = mid;
//         //     } else {
//         //         low = mid+1;
//         //         pos = mid;
//         //     }
//         // }

//         for(int i=0;i<n;i++) {
//             if(marbles[i] > a) cnt2++;   // a lies left side
//             else {
//                 cnt1++;
//             }
//         }

//         if(cnt1 > cnt2) {
//             cout<< a-1 <<endl;
//         } else {
//             cout<< a+1<<endl;
//         }

        


//     }
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n, a;
        cin >> n >> a;

        long long cnt1 = 0;   // v[i] < a
        long long cnt2 = 0;   // v[i] > a

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            if (x < a) cnt1++;
            else if (x > a) cnt2++;
        }

        if (cnt1 > cnt2) {
            cout << a - 1 << "\n";
        } else {
            cout << a + 1 << "\n";
        }
    }

    return 0;
}
