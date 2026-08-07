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
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
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
    for(int i=0; i<N; i++){
        if(A[i] %2 == 0){
            cout << S[i];
        }else{
            cout << T[i];
        }
    }
}