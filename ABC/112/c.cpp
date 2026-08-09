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
    vector<tuple<ll, ll, ll>> xyh(N);
    for(int i=0; i<N; i++){
        cin >> get<0>(xyh[i]) >> get<1>(xyh[i]) >> get<2>(xyh[i]);
    }
    sort(xyh.begin(), xyh.end(), [&](const auto l, const auto r){
        if(get<2>(l) != get<2>(r)) return get<2>(l) > get<2>(r);
        else return l > r;
    });
    for(int x=0; x<=100; x++){
        for(int y=0; y<=100; y++){
            ll H = get<2>(xyh[0])+abs(get<0>(xyh[0])-x) + abs(get<1>(xyh[0])-y);
            bool flag = true;
            for(int i=1; i<N; i++){
                if(get<2>(xyh[i]) != max(H - abs(get<0>(xyh[i])-x) - abs(get<1>(xyh[i])-y), (ll)0)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << x << " " << y << " " << H << "\n";
                return 0;
            }
        }
    }
}