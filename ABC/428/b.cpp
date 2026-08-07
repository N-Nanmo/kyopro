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
    map<string, int> mp;
    int N, K;
    string S;
    cin >> N >> K >> S;
    for(int i=0; i<N-K+1; i++){
        string tmp;
        tmp = S.substr(i, K);
        mp[tmp]++;
    }
    int maxnum = INT_MIN;
    for(auto p : mp){
        maxnum = max(maxnum, p.second);
    }
    cout << maxnum << "\n";
    vs ans;
    for(auto p : mp){
        if(maxnum == p.second){
            ans.emplace_back(p.first);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i != ans.size()-1){
            cout << " ";
        }else{
            cout << "\n";
        }
    }
}