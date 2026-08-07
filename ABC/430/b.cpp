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
    set<vvc> uq;
    for(int i=0; i<N-M+1; i++){
        for(int j=0; j<N-M+1; j++){
            vvc T(M, vc(M));
            for(int k=i; k<M+i; k++){
                for(int l=j; l<M+j; l++){
                    T[k-i][l-j] = S[k][l];
                }
            }
            uq.emplace(T);
        }
    }
    cout << uq.size() << "\n";
}