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
    vpi AB(N);
    for(int i=0; i<N; i++){
        cin >> AB[i].first >> AB[i].second;
    }
    vi SAB(N);
    for(int i=0; i<N; i++){
        SAB[i] = AB[i].first + AB[i].second;
    }
    sort(SAB.begin(), SAB.end());
    vpi A(N);
    vpi B(N);
    for(int i=0; i<N; i++){
        A[i].first = AB[i].first;
        A[i].second = i;
        B[i].first = AB[i].second;
        B[i].second = i;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int tmp = 0;
    if(A[0].second == B[0].second){
        tmp = min(max(A[0].first, B[1].first), max(A[1].first, B[0].first));
    }else{
        tmp = max(A[0].first, B[0].first);
    }
    cout << min(tmp, SAB[0]) << "\n";
}