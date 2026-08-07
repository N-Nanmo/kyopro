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
    vvi A(N, vi(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }
    vvi ans(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j] == 1){
                ans[i].emplace_back(j+1);
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " \n"[j == ans[i].size()-1];
        }
    }
    return 0;
}