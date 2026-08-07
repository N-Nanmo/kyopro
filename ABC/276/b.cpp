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
    vpi AB(M);
    vvi P(N);
    for(int i=0; i<M; i++){
        cin >> AB[i].first >> AB[i].second;
    }
    for(int i=0; i<M; i++){
        P[AB[i].first-1].emplace_back(AB[i].second);
        P[AB[i].second-1].emplace_back(AB[i].first);
    }
    for(int i=0; i<N; i++){
        sort(P[i].begin(), P[i].end());
        cout << P[i].size();
        cout << " ";
        if(P[i].size() == 0){
            cout << "\n";
        }
        for(int j=0; j<P[i].size(); j++){
            cout << P[i][j] << " \n"[j == P[i].size()-1];
        }
    }
}