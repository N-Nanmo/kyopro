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


void dfs(const vvi &G, int v, vvb &seen, const int &i, vvi &gy){
    seen[i][v] = true;
    gy[i].emplace_back(v);

    for(auto next_v : G[v]){
        if(seen[i][next_v]) continue;
        dfs(G, next_v, seen, i, gy);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vvi G(N+1);
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        G[x].emplace_back(y);
    }
    vvb seen(N+1, vb(N+1, false));
    vvi gy(N+1);
    for(int i=1; i<N+1; i++){
        dfs(G, i, seen, i, gy);
    }
    vb isblack(N+1);
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int a, v;
        cin >> a >> v;
        if(a == 1){
            isblack[v] = true;
        }else{
            bool ok = false;
            for(auto s : gy[v]){
                if(isblack[s]){
                    ok = true;
                    break;
                }
            }
            if(ok){
                cyes;
            }else{
                cno;
            }
        }
    }
}