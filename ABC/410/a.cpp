#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int K;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cin >> K;
    int ans = 0;
    for(int i=0; i<N; i++){
        if(A[i] >= K){
            ans++;
        }
    }
    cout << ans << "\n";
}