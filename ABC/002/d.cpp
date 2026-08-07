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
    int N;
    cin >> N;
    vpi P(N);
    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        P[i].first = stoi(S.substr(0, 4));
        P[i].second = stoi(S.substr(5, 4));
    }
    for(int i=0; i<N; i++){
        if(P[i].first % 10 != 0 && P[i].first % 10 != 5 && P[i].second % 10 != 0 && P[i].second % 10 != 5){
            if(P[i].first % 10 < 5){
                P[i].first = P[i].first - P[i].first % 10 + 5;
        }
    }
    vi pop;
    vpi Q;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) continue;
            if(P[i].first < P[j].first && P[i].second > P[j].second){
                pop.emplace_back(j);
            }else if(P[i].second == P[j].first){
                Q.emplace_back(P[i].first, P[j].second);
                pop.emplace_back(i);
                pop.emplace_back(j);
            }
        }
    }
    for(int i=0; i<N; i++){
        bool ok = true;
        for(auto p : pop){
            if(i == p) ok = false;
        }
        if(ok) Q.emplace_back(P[i]);
    }
    sort(Q.begin(), Q.end());
    for(int i=0; i<(int)Q.size(); i++){
        printf("%04d-%04d\n", Q[i].first, Q[i].second);
    }
}