#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> B(N,0);
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        B[i] = x + A;
    }
    for(int i=1; i<N; i++){
        int a = B[i] - B[i-1];
        if(a < A){
            B[i] += A - a;
        }
    }
    for(auto b : B){
        cout << b << endl;
    }
}