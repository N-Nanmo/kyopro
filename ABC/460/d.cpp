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
using vd = vector<double>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
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

int checkB(vvc &G, ll &i, ll &j, ll &H, ll &W){
    int cnt = 0;
    for(int y = i-1; y<=i+1; y++){
        for(int x = j-1; x<=j+1; x++){
            if(x == j && y == i || !(y >= 0 && y < H && x >= 0 && x < W)) continue;
            if(G[y][x] == '#'){
                cnt++;
            }
        }
    }
    return cnt;
}

bool checkW(vvc &G, ll &i, ll &j, ll &H, ll &W){
    int cnt = 0;
    for(int y = i-1; y<=i+1; y++){
        for(int x = j-1; x<=j+1; x++){
            if(x == y || !(y >= 0 && y < H && x >= 0 && x < W)) continue;
            if(G[y][x] == '.'){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll H, W;
    cin >> H >> W;
    vvc G(H, vc(W));
    queue<pll> q;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> G[i][j];
        }
    }
    vvc ans(H, vc(W, '.'));
    ans = G;
    for(ll i=0; i<H; i++){
        for(ll j=0; j<W; j++){
            if(G[i][j] == '#' && !checkW(G, i, j, H, W)){
                ans[i][j] = '.';
            }
        }
    }
    G = ans;
    for(ll i=0; i<H; i++){
        for(ll j=0; j<W; j++){
            if(ans[i][j] == '#'){
                q.emplace(i, j);
            }
        }
    }
    queue<pll> nq;
    vpll tmpB;
    while(!q.empty() || !nq.empty()){
        if(q.empty()){
            nq.swap(q);
            for(auto b: tmpB){
                G[b.first][b.second] = '#';
            }
            tmpB.clear();
            /*for(int i=0; i<H; i++){
                for(int j=0; j<W; j++){
                    cout << ans[i][j];
                }
                cout << "\n";
            }
            cout << "\n";
            */
        }
        pll crr = q.front();
        q.pop();
        ll y = crr.first;
        ll x = crr.second;
        //cout << "x:" << x << "y:" << y << "\n";
        for(ll i=y-2; i<=y+2; i++){
            for(ll j=x-2; j<=x+2; j++){
                //cout << i << " " << j << "\n";
                if((i != y-2 && i != y+2 && j != x-2 && j != x+2) || i < 0 || i >= H || j < 0 || j >= W || G[i][j] == '#') continue;
                if(!checkB(G, i, j, H, W)){
                    ans[i][j] = '#';
                    tmpB.emplace_back(i, j);
                    nq.emplace(i, j);
                }
            }
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}