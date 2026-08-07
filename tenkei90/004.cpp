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
    ll H, W;
    cin >> H >> W;
    vvll A(H, vll(W));
    vll T(H);
    vll Y(W);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> A[i][j];
        }
    }
    for(int i=0; i<H; i++){
        int sum=0;
        for(int j=0; j<W; j++){
            sum += A[i][j];
        }
        T[i] = sum;
    }
    for(int i=0; i<W; i++){
        int sum = 0;
        for(int j=0; j<H; j++){
            sum += A[j][i];
        }
        Y[i] = sum;
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << T[i] + Y[j] - A[i][j];
            if(j < W-1) cout << " ";
            else cout << "\n";
        }
    }
}