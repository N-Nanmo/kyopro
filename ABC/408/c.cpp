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
    int N, M;
    cin >> N >> M;
    vi A(N);
    for(int i=0; i<M; i++){
        int l, r;
        cin >> l >> r;
        A[l-1]++;
        if(r < N) A[r]--;
    }
    for(int i=1; i<N; i++){
        A[i] += A[i-1];
    }
    sort(A.begin(), A.end());
    cout << A[0] << endl;
}