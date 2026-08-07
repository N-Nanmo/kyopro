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
using vf = vector<float>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
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
    int Y = stoi(S.substr(0, 4));
    int M = stoi(S.substr(5, 2));
    int D = stoi(S.substr(8, 2));
    if(2019 > Y){
        cout << "Heisei\n";
    }else if(2019 < Y){
        cout << "TBD\n";
    }else{
        if(4 > M){
            cout << "Heisei\n";
        }else if(4 < M){
            cout << "TBD\n";
        }else{
            if(30 >= M){
                cout << "Heisei\n";
            }else{
                cout << "TBD\n";
            }
        }
    }
}