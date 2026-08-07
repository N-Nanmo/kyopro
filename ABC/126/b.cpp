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
    string S;
    cin >> S;
    int Y = stoi(S.substr(0, 2));
    int X = stoi(S.substr(2, 2));
    if(0 < Y && Y <= 12 && 0 < X && X <= 12){
        cout << "AMBIGUOUS\n";
    }else if(0 < Y && Y <= 12 && 0 <= X && X < 100){
        cout << "MMYY\n";
    }else if(0 <= Y  && Y < 100 && 0 < X && X <= 12){
        cout << "YYMM\n";
    }else{
        cout << "NA\n";
    }
}