#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    int sum = 0;
    for(int i=0; i<N; i++){
        sum += A[i];
    }
    if(sum <= M){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}