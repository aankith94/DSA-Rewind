#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;          // read integer n
    cin.ignore();      // remove leftover newline

    string str;
    getline(cin, str); // now safely read the whole string

    if (str.length() == 0) {
        cout << -2;
        return 0;
    }

    long long maxNum = -1;
    string current = "";

    for (char c : str) {
        if (isdigit(c)) {
            current += c;
        } else {
            if (!current.empty()) {
                maxNum = max(maxNum, stoll(current));
                current = "";
            }
        }
    }

    // Check last number
    if (!current.empty()) {
        maxNum = max(maxNum, stoll(current));
    }

    cout << maxNum;
    return 0;
}
