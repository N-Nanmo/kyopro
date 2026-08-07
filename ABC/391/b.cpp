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
    int N, M;
    cin >> N >> M;
    vvc S(N, vc(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> S[i][j];
        }
    }
    vvc T(M, vc(M));
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            cin >> T[i][j];
        }
    }
    for(int i=0; i<=N-M; i++){
        for(int j=0; j<=N-M; j++){
            bool flag = true;
            for(int m=0; m<M; m++){
                for(int n=0; n<M; n++){
                    if(S[i+m][j+n] != T[m][n]) flag = false;
                }
            }
            if(flag){
                cout << i+1 << " " << j+1 << "\n";
                return 0;
            }
        }
    }
}