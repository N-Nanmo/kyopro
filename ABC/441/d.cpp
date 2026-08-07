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
    int N;
    cin >> N;
    string S;
    cin >> S;
    vi A(N+1);
    int ans = 0;
    for(int i=0; i<N; i++){
        if(S[i] == 'A'){
            A[i+1] = 1;
        }else if(S[i] == 'C'){
            A[i+1] = 0;
        }else{
            A[i+1] = -1;
        }
    }
    for(int i=1; i<N+1; i++) A[i] += A[i-1];
    for(int i=0; i<N+1; i++){
        for(int j=i+1; j<N+1; j++){
            if(A[j] - A[i] > 0) ans++;
        }
    }
    cout << ans << "\n";
}