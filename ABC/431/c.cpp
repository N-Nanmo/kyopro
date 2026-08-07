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
    int N, M, K;
    cin >> N >> M >> K;
    vll H(N);
    vll B(M);
    int cnt_h = 0;
    int cnt_b = 0;
    int ans = 0;
    for(int i=0; i<N; i++){
        cin >> H[i];
    }
    for(int i=0; i<M; i++){
        cin >> B[i];
    }
    sort(H.begin(), H.end());
    sort(B.begin(), B.end());
    while(cnt_h < N && cnt_b < M){
        if(H[cnt_h] > B[cnt_b]){
            cnt_b++;
        }else{
            ans++;
            cnt_h++;
            cnt_b++;
        }
    }
    if(K <= ans){
        cyes;
    }else{
        cno;
    }
}