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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    vll A(N);
    cin >> A;
    ll Q;
    cin >> Q;
    vpll B(N);
    for(int i=0; i<N; i++){
        B[i].second = i;
        B[A[i]-1].first++;
    }
    vll C(N);
    for(int i=0; i<N; i++){
        C[i] = B[i].first;
    }
    ll mx = *max_element(all(C));
    vpll E;
    ll crr = N;
    vb B(N);
    while(Q--){
        ull X;
        cin >> X;
        if(X <= N){
            cout << A[X-1] << "\n";
        }else if(X-N >= C[N-1]){
            cout << (X-1)%N+1 << "\n";
        }else{
            for(;crr <= X; crr++){
                sort(all(B), [mx](auto const& l, auto const& r){
                    if(mx <= l.first) return true;
                    else if(mx <= r.first) return false;
                    else return l.second < r.second;
                });
            }
        }
    }
}