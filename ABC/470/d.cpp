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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vi P(N);
    cin >> P;
    vector<pair<int, pi>> querry;
    for(int i=0; i<Q; i++){
        pair<int, pi> tmp;
        int a;
        cin >> a;
        if(a == 1){
            int x, y;
            cin >> x >> y;
            tmp.second = {x, y};
        }
        tmp.first = a;
        querry.emplace_back(tmp);
    }
    sort(rall(querry));
    int i=0;
    while(querry[i].first == 2){
        i++;
    }
    if(true){
        vi ans(N);
        for(int i=0; i<N; i++){
            ans[P[i]-1] = i+1;
        }
        P = ans;
    }
    for(int i=0; i<N; i++){
        cout << P[i] << " \n"[i==N-1];
    }
    while(i < Q){
        int c;
        c = P[querry[i].second.first-1];
        P[querry[i].second.first-1] = P[querry[i].second.second-1];
        P[querry[i].second.second-1] = c;
        i++;
    }
    for(int i=0; i<N; i++){
        cout << P[i] << " \n"[i==N-1];
    }
}