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
    int N, M;
    cin >> N >> M;
    vpi AB(N);
    for(int i=0; i<N; i++) cin >> AB[i].first >> AB[i].second;
    sort(AB.begin(), AB.end());
    int S = 1;
    int sumn = 0;
    int cnt = 0;
    for(int i=0; i<N; i++){
        if(AB[i].first == S){
            cnt++;
            sumn+=AB[i].second;
        }else{
            S++;
            cout << (float)sumn / (float)cnt << "\n";
            sumn = AB[i].second;
            cnt = 1;
        }
    }
    cout << (float)sumn / (float)cnt << "\n";
}