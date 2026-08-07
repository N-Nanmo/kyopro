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
    vi A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int last = -1;
    vpi AP;
    int crr = -1;
    for(int i=0; i<N; i++){
        if(last != A[i]){
            AP.emplace_back(make_pair(A[i], 1));
            crr++;
            last = A[i];
        }else{
            AP[crr].second++;
        }
    }
    for(int i=1; i<AP.size(); i++){
        AP[i].second += AP[i-1].second;
    }
    int ans = -1;
    int min_abs = INT_MAX;
    for(int i=0; i<AP.size(); i++){
        if(min_abs >= abs(N - AP[i].second*2)){
            ans = i;
            min_abs = abs(N - AP[i].second*2);
        }
    }
    cout << AP[ans+1].first << "\n";
}