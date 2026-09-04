#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC optimize("O3")
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vull = vector<ull>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vf = vector<float>;
using vd = vector<double>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvull = vector<vector<ull>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
using vvd = vector<vector<double>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <typename T>
inline istream& operator >> (istream& is, vector<T>& v){
    for(size_t i=0; i<v.size(); i++){
        is >> v[i];
    }
    return is;
}
template <typename T, typename U>
inline istream& operator >> (istream& is, vector<pair<T,U>>& v){
    for(size_t i=0; i<v.size(); i++){
        is >> v[i].first >> v[i].second;
    }
    return is;
}
template <typename T>
inline istream& operator >> (istream& is, vector<vector<T>>& v){
    for(size_t i=0; i<v.size(); i++){
        for(size_t j=0; j<v[i].size(); j++){
            is >> v[i][j];
        }
    }
    return is;
}
template <typename T, typename U, typename S, typename V>
inline istream& operator >> (istream& is, vector<pair<pair<T,U>, pair<S,V>>>& v){
    for(size_t i=0; i<v.size(); i++){
        is >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
    }
    return is;
}
const double PI = 3.14159265359;
vi dx = {0, -1, 0, 1};
vi dy = {1, 0, -1, 0};

void dfs(vb &B, ll crr, vvll &G, ll &cnt, bool &finished, ll &last, vll &cntN){
    if(B[crr]){
        if((cnt-cntN[crr])%2 == 1 && cnt != 1){
            cout << (cnt-cntN[crr]) << "\n";
            cnt = (cnt-cntN[crr]);
            finished = true;
        }
        return;
    }
    B[crr] = true;
    ll tmp = last;
    last = crr;
    cntN[crr] = cnt;

    for(ll g : G[crr]){
        if(g == tmp) continue;
        cnt++;
        dfs(B, g, G, cnt, finished, last, cntN);
        cnt--;
        if(finished){
            if(cnt < 0){
                return;
            }
            cout << crr+1;
            if(cnt == 0){
                cout << "\n";
            }else{
                cout << " ";
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while(T--){
        ll N, M;
        cin >> N >> M;
        vvll G(N);
        vvb passed(N);
        for(int i=0; i<M; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].emplace_back(b);
            G[b].emplace_back(a);
        }
        vb B(N, false);
        ll cnt = 0;
        bool finished = false;
        ll last = -1;
        vll cntN(N, -1);
        dfs(B, 0, G, cnt, finished, last, cntN);
        if(!finished) cout << "-1\n";
    }
}