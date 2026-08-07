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
    if(S[0] != 'A'){
        cout << "WA\n";
        return 0;
    }
    int cnt = 0;
    int Cp = -1;
    for(int i=2; i<=S.size()-2; i++){
        if(S[i] == 'C'){
            cnt++;
            Cp = i;
        }
    }
    if(cnt != 1){
        cout << "WA\n";
        return 0;
    }
    for(int i=1; i<S.size(); i++){
        if(i != Cp){
            if(isupper(S[i])){
                cout << "WA\n";
                return 0;
            }
        }
    }
    cout << "AC\n";
}