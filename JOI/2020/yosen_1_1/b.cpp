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
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    string S;
    cin >> N >> S;
    int J=0, O=0, I=0;
    for(int i=0; i<N; i++){
        if(S[i] == 'J') J++;
        else if(S[i] == 'O')O++;
        else I++;
    }
    for(int i=0; i<J; i++){
        cout << "J";
    }
    for(int i=0; i<O; i++){
        cout << "O";
    }
    for(int i=0; i<I; i++){
        cout << "I";
    }
    cout << "\n";
}