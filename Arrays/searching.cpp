#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int X;
    cin >> X;

    // print the position of X
    int pos = -1;
    for(int i=0;i<N;i++) {
        if(arr[i] == X) {
            pos = i;
            break;
        } 
    }

    cout<< pos <<endl;

    return 0;
}