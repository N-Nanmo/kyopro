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
    int N,K;
    cin >> N >> K;
    vi hate(K);
    for(int i=0; i<K; i++) cin >> hate[i];
    sort(hate.begin(), hate.end());
    for(int i=N;;i++){
        string s = to_string(i);
        bool ok = true;
        for(int j=0; j<s.size(); j++){
            if(find(hate.begin(), hate.end(), s[j] - '0') != hate.end()){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << i << "\n";
            return 0;
        }
    }
}