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
    int b1 = -1, b2 = -1, r1 = -1, r2 = -1, k = -1;
    for(int i=0; i<S.size(); i++){
        if(S[i] == 'B'){
            if(b1 == -1){
                b1 = i;
            }else{
                b2 = i;
            }
        }else if(S[i] == 'R'){
            if(r1 == -1){
                r1 = i;
            }else{
                r2 = i;
            }
        }else if(S[i] == 'K'){
            k = i;
        }
    }
    if(b1%2 != b2%2 && r1 <= k && k <= r2){
        cyes;
    }else{
        cno;
    }
}