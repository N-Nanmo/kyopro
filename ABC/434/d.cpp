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
    int N;
    cin >> N;
    vvi grid(2000, vi(2000, 0));
    vvi A(N, vi(4));
    for(int i=0; i<N; i++){
        for(int j=0; j<4; j++){
            cin >> A[i][j];
        }
    }
    for(int i=0; i<N; i++){
        grid[A[i][0]-1][A[i][2]-1]++;
        if(A[i][1] < 2000 && A[i][3] < 2000){
            grid[A[i][1]][A[i][3]]++;
        }
        if(A[i][3] < 2000){
            grid[A[i][0]-1][A[i][3]]--;
        }
        if(A[i][1] < 2000){
            grid[A[i][1]][A[i][2]-1]--;
        }
    }
    for(int i=1; i<2000; i++){
        for(int j=0; j<2000; j++){
            grid[i][j] += grid[i-1][j];
        }
    }
    for(int i=0; i<2000; i++){
        for(int j=1; j<2000; j++){
            grid[i][j] += grid[i][j-1];
        }
    }
    int nokori = 2000*2000;
    for(int i=0; i<2000; i++){
        for(int j=0; j<2000; j++){
            if(grid[i][j] != 0){
                nokori--;
            }
        }
    }
    vi have(N,0);
    for(int t=0; t<N; t++){
        for(int i=A[t][0]-1; i<A[t][1]; i++){
            for(int j=A[t][2]-1; j<A[t][3]; j++){
                if(grid[i][j] == 1){
                    have[t]++;
                }
            }
        }
    }
    for(int i=0; i<N; i++){
        cout << have[i] + nokori << "\n";
    }
}