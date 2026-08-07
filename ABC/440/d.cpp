#include <bits/stdc++.h>
#include <atcoder/all>
//#pragma GCC optimize("O3")
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vf = vector<float>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
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
    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    for(ll i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vll R(N);
    R[N-1] = 1;
    for(ll i=N-2; i>=0; i--){
        if(A[i+1] - A[i] == 1){
            R[i] = R[i+1] + 1;
        }else{
            R[i] = 1;
        }
    }
    vpll XY(Q);
    for(ll i=0; i<Q; i++) cin >> XY[i].first >> XY[i].second;
    for(ll i=0; i<Q; i++){
        ll tmp = lower_bound(A.begin(), A.end(), XY[i].first) - A.begin();
        if(A[tmp] == XY[i].first){
            XY[i].first += R[tmp];
        }
        ll ans = XY[i].second + XY[i].first - 1;
        tmp = lower_bound(A.begin(), A.end(), ans) - A.begin();
        if(A[tmp] == ans){
            ans += R[tmp];
        }
        cout << ans << "\n";
    }
}