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
    ll N, K;
    cin >> N >> K;
    vll F(1 << N, 0);
    ll i = (1 << (N-1)) - 1;
    ll j = (1 << (N-2)) - 1;
    ll tmp;
    if(K % 2 == 0){
        tmp = K /2;
        F[i] = tmp;
        F[i+1] = tmp;
    }else{
        tmp = K /2 + 1;
        F[i+1] = tmp;
        F[i] = tmp - 1;
    }
    if(N == 1){
        cout << K % 2 << "\n";
        cout << F[i] << ' ' << F[i+1] << "\n";
        cout << i << ' ' << j << "\n";
        return 0;
    }else{
        while(i > 0){
            for(int k=0; k<N-1; k++){
                for(int l=0; l<(1 << (k+1)); l++){
                    for(int m=0; m<2; m++){
                    }
                }
            }
        }
    }
}