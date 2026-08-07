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
    int N;
    cin >> N;
    if(N/3600 < 10 && N/3600 > 0){
        cout << "0" << N/3600;
    }else if(N/3600 == 0){
        cout << "00";
    }else{
        cout << N/3600;
    }
    cout << ":";
    if(N%3600/60 == 0){
        cout << "00";
    }else if(N%3600/60 < 10){
        cout << "0" << N%3600/60;
    }else{
        cout << N%3600/60;
    }
    cout << ":";
    if(N%60 == 0){
        cout << "00";
    }else if(N%60 < 10){
        cout << "0" << N%60;
    }else{
        cout << N%60;
    }
    cout << "\n";
}