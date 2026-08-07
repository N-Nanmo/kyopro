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
    ll N;
    cin >> N;
    vector<pair<pair<int, int>,int>> S;
    for(int x=0; x<=N; x++){
        for(int y=0; y<=N; y++){
            for(int z=0; z<=N; z++){
                if(x+y+z > N) continue;
                S.emplace_back(make_pair(x, y), z);
            }
        }
    }
    sort(S.begin(), S.end());
    for(int i=0; i<S.size(); i++){
        cout << S[i].first.first << " " << S[i].first.second << " " << S[i].second << "\n";
    }
}