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
    char a;
    bool af = false;
    char b;
    bool bf = false;
    for(int i=0; i<S.size(); i++){
        if(af == false){
            a = S[i];
            af = true;
        }else{
            if(bf == false && a != S[i]){
                b = S[i];
                bf = true;
            }else{
                if(a == S[i]){
                    if(bf == false) continue;
                    cout << b << "\n";
                    return 0;
                }else{
                    if(af = false) continue;
                    cout << a << "\n";
                    return 0;
                }
            }
        }
    }
    cout << b << "\n";
}