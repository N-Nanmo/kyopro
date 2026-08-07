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
    vpi AB(N);
    for(int i=0; i<N; i++){
        cin >> AB[i].first >> AB[i].second;
    }
    sort(AB.begin(), AB.end());
    int l=AB[0].first;
    int r=AB[0].second;
    int ans = 1;
    int cnt = 0;
    bool karamari = false;
    for(int i=1; i<N; i++){
        if(AB[i].second > r && AB[i].first != l){
            ans++;
        }
        r = AB[i].second;
        l = AB[i].first;
    }
    cout << ans << "\n";
}