#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<vector<int>> df(2000000, vector<int>());
/*bool dfs(ll T, ll &N, ll count, ll &goal){
    for(auto &Tl : df[T]){
        if(Tl == goal && T != goal){
            return true;
        }else if(cout > N){
            continue;
        }else{
            dfs(Tl, N, count + 1, goal);
        }
    }
}*/

int main() {
    ll N, M, count = 0, T=0, start;
    cin >> N >> M;
    if(N != M){
        cout << "No\n";
        return 0;
    }
    bool first_a = true;
    for(int i=0; i<M; i++){
        ll  a, b;
        cin >> a >> b;
        if(first_a){
            start = a;
        }
        df[a].emplace_back(b);
        df[b].emplace_back(a);
    }
    
    //dfs(start, N, count, start);
}