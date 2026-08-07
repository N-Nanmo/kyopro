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
    string S, T;
    cin >> S >> T;
    for(int i=0; i<S.size(); i++){
        if(S[i] != T[i]){
            if(S[i] == '@'){
                if(T[i] != 'a' && T[i] != 't' && T[i] != 'c' && T[i] != 'o' && T[i] != 'd' && T[i] != 'e' && T[i] != 'r' && T[i] != '@'){
                    cout << "You will lose\n";
                    return 0;
                }
            }else if(T[i] == '@'){
                if(S[i] != 'a' && S[i] != 't' && S[i] != 'c' && S[i] != 'o' && S[i] != 'd' && S[i] != 'e' && S[i] != 'r' && S[i] != '@'){
                    cout << "You will lose\n";
                    return 0;
                }
            }else{
                cout << "You will lose\n";
                return 0;
            }
        }
    }
    cout << "You can win\n";
}