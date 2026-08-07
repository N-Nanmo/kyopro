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
    if(S[0] == S[1] && S[1] == S[2] && S[2] == S[3]){
        cout << "Weak\n";
        return 0;
    }
    bool ok = true;
    for(int i=0; i<3; i++){
        if(!(S[i] == '9' && S[i+1] == '0' || S[i]+1 == S[i+1])){
            ok = false;
        }
    }
    if(ok){
        cout << "Weak\n";
    }else{
        cout << "Strong\n";
    }
}