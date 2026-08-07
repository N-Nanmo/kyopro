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
using vc = vector<char>;
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
    vvc C(N, vc(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> C[i][j];
        }
    }
    for(int i=0; i<N; i++){
        bool ok = true;
        for(int j=0; j<N-1; j++){
            if(C[i][j] != C[i][j+1]){
                ok = false;
            }
        }
        if(ok){
            cyes;
            return 0;
        }
    }
    for(int i=0; i<N; i++){
        bool ok = true;
        for(int j=0; j<N-1; j++){
            if(C[j+1][i] != C[j][i]){
                ok = false;
            }
        }
        if(ok){
            cyes;
            return 0;
        }
    }
    cno;
}