#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC optimize("O3")
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using Vi = vector<int>;
using Vll = vector<ll>;
using Vs = vector<string>;
using VVi = vector<vector<int>>;
using VVll = vector<vector<ll>>;
using VVs = vector<vector<string>>;
using VVc = vector<vector<char>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N,t=1;
        cin >> N;
        for(int j=0; j<N; j++){
            t *= 2;
        }
        Vll A(t);
        for(int j=0; j<t; j++){
            cin >> A[j];
        }
        if(A[0] > A[t-1]){
            reverse(A.begin(), A.end());
        }
        for(int j=0; j<N; j++){
            
        }
    }
}