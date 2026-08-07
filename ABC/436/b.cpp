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
    vvi A(N, vi(N, -1));
    A[0][(N-1)/2] = 1;
    int r=0, c=(N-1)/2, k=1;
    for(int i=0; i<N*N-1; i++){
        if(A[(r+N-1)%N][(c+1)%N] == -1){
            A[(r+N-1)%N][(c+1)%N] = k+1;
            r = (r+N-1)%N;
            c = (c+1)%N;
        }else{
            A[(r+1)%N][c] = k+1;
            r = (r+1)%N;
        }
        k++;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << A[i][j] << " \n"[j==N-1];
        }
    }
}