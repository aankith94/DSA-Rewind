#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    int minVal = A[0];
    int pos = 0;

    for(int i=0;i<N;i++) {
        if(A[i] < minVal) {
            minVal = A[i];
            pos = i;
        }
        
    }

    cout<< minVal<< " "<< pos+1<< endl;

    return 0;
}
