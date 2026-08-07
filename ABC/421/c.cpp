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
    string S;
    cin >> S;
    ll ans_a = 0;
    vi A(N);
    ll a_cnt=0;
    ll cnt = 0;
    for(ll i=0; i<N*2; i++){
        if(S[i] == 'A'){
            A[a_cnt] = i;
            a_cnt++;
        }
    }
    for(ll i=0; i<N; i++){
        ans_a += abs(A[i]-cnt);
        cnt += 2;
    }
    cnt = 1;
    ll ans_b = 0;
    for(ll i=0; i<N; i++){
        ans_b += abs(A[i]-cnt);
        cnt += 2;
    }
    cout << min(ans_a, ans_b) << "\n";
}