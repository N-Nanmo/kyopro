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
    vvb B(3, vb(3, false));
    vvi A(3, vi(3));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> A[i][j];
        }
    }
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int b;
        cin >> b;
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(A[j][k] == b) B[j][k] = true;
            }
        }
    }
    for(int i=0; i<3; i++){
        bool bingo = true;
        for(int j=0; j<3; j++){
            if(B[i][j] == false) bingo = false;
        }
        if(bingo){
            cyes;
            return 0;
        }
    }
    for(int j=0; j<3; j++){
        bool bingo = true;
        for(int i=0; i<3; i++){
            if(B[i][j] == false) bingo = false;
        }
        if(bingo){
            cyes;
            return 0;
        }
    }
    if(B[0][0] && B[1][1] && B[2][2] || B[0][2] && B[1][1] && B[2][0]){
        cyes;
        return 0;
    }
    cno;
}