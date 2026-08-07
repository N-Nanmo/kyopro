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
    int N;
    cin >> N;
    vll A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vll cut(N,0);
    for(int i=0; i<N; i++){
        ll cnt=0;
        ll a = A[i];
        while(a%2==0){
            cnt++;
            a /= 2;
        }
        cut[i] = 1 << cnt;
    }
    vll rui(N+1);
    rui[0] = 0;
    for(int i=0; i<N-1; i++){
        rui[i+1] = cut[i] + rui[i];
    }
    ll Q;
    cin >> Q;
    vll X(Q);
    for(int i=0; i<Q; i++){
        cin >> X[i];
    }
    for(int i=0; i<Q; i++){
        ll x = X[i];
        ll right=N, left=0;
        while(right - left > 1){
            ll m = (right+left)/2;
            if(x <= rui[m]){
                right = m;
            }else{
                left = m;
            }
        }
        cout << A[left] / cut[left] << "\n";
    }
}