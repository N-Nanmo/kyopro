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
    vs S(3);
    for(int i=0; i<3; i++){
        cin >> S[i];
    }
    bool a = false, b = false, c = false, d = false;
    for(int i=0; i<3; i++){
        if(S[i] == "ABC") a = true;
        if(S[i] == "ARC") b = true;
        if(S[i] == "AGC") c = true;
        if(S[i] == "AHC") d = true;
    }
    if(!a){
        cout << "ABC\n";
    }else if(!b){
        cout << "ARC\n";
    }else if(!c){
        cout << "AGC\n";
    }else{
        cout << "AHC\n";
    }
}