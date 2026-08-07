#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC optimize("O3")
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vi A(N);
    int X;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cin >> X;
    for(int i=0; i<N; i++){
        if(A[i] == X){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}