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
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vector<ull> T;
    if(N <= 2){
        T.resize(3, 0);
    }else{
        T.resize(N, 0);
    }
    T[0] = 0;
    T[1] = 0;
    T[2] = 1;
    for(ll i=3; i<N; i++){
        T[i] = (T[i-1] + T[i-2] + T[i-3]) % 10007;
    }
    cout << T[N-1]<< "\n";
}