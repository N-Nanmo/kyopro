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
    string S;
    cin >> S;
    ll cnt=0;
    for(int pop=0;pop <= S.size(); pop++){
        int popnum = S[S.size()-1-pop] - '0';
        cnt += popnum;
        for(int i=0; i<S.size()-pop; i++){
            if(S[i] - '0' - popnum < 0){
                S[i] = S[i] - '0' - popnum + 10 + '0';
            }else{
                S[i] = S[i] - '0' - popnum + '0';
            }
        }
    }
    cnt += S.size();
    cout << cnt << "\n";
}