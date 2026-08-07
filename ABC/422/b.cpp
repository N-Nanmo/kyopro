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

bool isok(int H, int W, int i, int j, vvc &C){
    int cnt = 0;
    if(i > 0){
        if(C[i-1][j] == '#') cnt++;
    }
    if(i < H-1){
        if(C[i+1][j] == '#') cnt++;
    }
    if(j > 0){
        if(C[i][j-1] == '#') cnt++;
    }
    if(j < W-1){
        if(C[i][j+1] == '#') cnt++;
    }
    if(cnt ==2 || cnt == 4) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vvc C(H, vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> C[i][j];
        }
    }
    bool ans = true;
    for(int i =0; i<H; i++){
        for(int j=0; j<W; j++){
            if(C[i][j] == '#' &&  isok(H, W, i, j, C) == false){
                ans = false;
            }
        }
    }
    if(ans) cyes;
    else cno;
}