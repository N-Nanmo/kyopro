#include <bits/stdc++.h>
#include <atcoder/all>
//#pragma GCC optimize("O3")
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

class Timer{
    chrono::system_clock::time_point start;
    public:
        Timer() : start(chrono::system_clock::now()) {}
    
        double count(){
            chrono::duration<double> Time_ = chrono::system_clock::now() - start;
            return Time_.count();
        }

        bool is_under(double x){
            return (this -> count()) < x;
        }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Timer timer;
    ll N;
    cin >> N;
    vll P(N);
    vll Q(N);
    cin >> P >> Q;
    modint998244353 pum = 0;
    ll cnt = 1;
    for(int i=2; i<=N-1; i++) cnt *= i;
    pum = cnt*N;
    vb B(N, false);
    for(int i=0; i<N-1; i++){
        for(int j=0; j<P[i]; j++){
            if(!B[j]) pum -= cnt;
        }
        B[P[i]-1] = true;
        cnt /= (N-1-i);
    }
    cnt = 1;
    for(int i=2; i<=N-1; i++) cnt *= i;
    modint998244353 qum = cnt*N;
    for(int i=0; i<N; i++) B[i] = false;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<Q[i]; j++){
            if(!B[j]) qum -= cnt;
        }
        B[Q[i]-1] = true;
        cnt /= (N-1-i);
    }
    cout << max((int)0, pum.val() - qum.val() - 1) << "\n";
    cout << "time: " << timer.count() << "\n";
}