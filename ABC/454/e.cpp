#include <bits/stdc++.h>
#include <atcoder/all>
//#pragma GCC optimize("O3")
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

vi dx = {0, 0, -1, 1};
vi dy = {1, -1, 0, 0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int N, A, B;
        cin >> N >> A >> B;
        queue<pair<int, int>> q;
        q.emplace(make_pair(0, 0));
        vvb seen(N, vb(N));
        vector<vector<pi>> parent(N, vpi(N));
        bool flag = false;
        while(!q.empty()){
            pi crr = q.front();
            q.pop();
            if(crr.first == N-1 && crr.second == N-1) continue;
            int x = crr.first;
            int y = crr.second;
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if(nx == A-1 && ny == B-1) continue;
                if(seen[ny][nx]){
                    parent[ny][nx] = crr;
                    continue;
                }
                q.emplace(make_pair(nx, ny));
                parent[ny][nx] = crr;
                seen[ny][nx] = true;
                if(ny == N-1 && nx == N-1){
                    flag = true;
                }
            }
        }
        if(!flag){
            cno;
            continue;
        }else{
            cyes;
        }
        int tx = N-1, ty = N-1;
        vc route;
        while(tx != 0 || ty != 0){
            pi bk = parent[ty][tx];
            int x = bk.first;
            int y = bk.second;
            if(tx  == x-1) route.emplace_back('L');
            else if(tx == x+1) route.emplace_back('R');
            else if(ty == y-1) route.emplace_back('U');
            else route.emplace_back('D');
            if(x == 0 && y == 0){
                break;
            }
            tx = x;
            ty = y;
        }
        reverse(all(route));
        for(int i=0; i<route.size(); i++){
            cout << route[i];
        }
        cout << "\n";
    }
}