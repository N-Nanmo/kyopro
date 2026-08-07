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
    vpi A(N);
    for(int i=0; i<N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    vi cr(N);
    for(int i=0; i<N; i++){
        cr[i] = A[i].first;
    }
    sort(A.begin(),A.end());
    for(int i=0; i<N;i++){
        int maxnum = -1;
        int minnum = INT_MAX;
        if(A[N-1].second != i){
            maxnum = A[N-1].first;
        }else{
            maxnum = A[N-2].first;
        }
        if(A[0].second != i){
            minnum = A[0].first;
        }else{
            minnum = A[1].first;
        }
        cout << max(abs(cr[i] - maxnum), abs(cr[i] - minnum)) << "\n";
    }
}