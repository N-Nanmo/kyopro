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
    string S;
    cin >> S;
    vector<pair<char, int>> M;
    char last = -1;
    int cnt = 0;
    for(int i=0; i<S.size(); i++){
        if(last == -1){
            last = S[i];
            cnt++;
        }else if(last != S[i]){
            M.emplace_back(make_pair(last, cnt));
            cnt = 1;
            last = S[i];
        }else{
            cnt++;
        }
    }
    if(cnt != 0){
        M.emplace_back(make_pair(last, cnt));
    }
    int ans = 0;
    for(int i=0; i<M.size()-1; i++){
        if(M[i+1].first - M[i].first == 1){
            ans += min(M[i].second, M[i+1].second);
        }
    }
    cout << ans << "\n";
}
