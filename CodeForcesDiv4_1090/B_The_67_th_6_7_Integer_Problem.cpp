#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a[7];
        int sum = 0, mx = -100;

        for(int i = 0; i < 7; i++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] > mx) mx = a[i];
        }

        int result = 2 * mx - sum;
        cout << result << endl;
    }

    return 0;
}