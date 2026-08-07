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
    int M;
    cin >> M;
    if(M < 100){
        cout << "00";
    }else if(M <= 5000){
        if(M/100 < 10){
            cout << "0";
        }
        cout << M/100;
    }else if(M <= 30000){
        cout << M/1000+50;
    }else if(M <= 70000){
        cout << (M/1000-30)/5 + 80;
    }else{
        cout << "89";
    }
    cout << "\n";
}