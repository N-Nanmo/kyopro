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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull N, M,ans = 0;
    cin >> N >> M;
    vector<pair<ull,ull>> S(M);
    for(ull i=0; i<M; i++){
        cin >> S[i].first >> S[i].second;
    }
    sort(S.begin(),S.end(),[](pair <ull,ull> a, pair<ull,ull> b){
        return a.first - a.second < b.first - b.second;
        return a.first > b.first;
    });
    while(true){
        bool ok = false;
        for(auto [a, b] : S){
            if(N >= a){
                ull n = (N-a)/(a-b) + 1;
                N-= n * (a-b);
                ans+= n;
                ok = true;
                break;
            }
        }
        if(!ok) break;
    }
    cout << ans << endl;
}