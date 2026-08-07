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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vpll A(N);
    for(int i=0; i<N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(all(A));
    ll ans = 1;
    ll cnt = 1;
    ll lastn = A[0].second;
    ll mn = -1, mx = -1;
    bool same = false;
    for(int i=1; i<N; i++){
        if(A[i-1].first + 1 < A[i].first){
            same = false;
            ans = max(ans, cnt);
            cnt = 1;
            continue;
        }
        if(A[i-1].first == A[i].first){
            if(same){
                mn = min(A[i-1].second, min(A[i].second, mn));
                mx = max(A[i-1].second, max(A[i].second, mx));
            }else{
                mn = min(A[i-1].second, A[i].second);
                mx = max(A[i-1].second, A[i].second);
            }
            same = true;
            continue;
        }
        if(A[i-1].first + 1 == A[i].first){
            if(same){
                if(mn < A[i].second){
                    cnt++;
                }else{
                    ans = max(ans, cnt);
                    cnt = 1;
                }
            }else{
                if(lastn < A[i].second){
                    cnt++;
                }else{
                    ans = max(ans, cnt);
                    cnt = 1;
                }
            }
        }
        lastn = A[i].second;
        same = false;
    }
    ans = max(ans, cnt);
    cout << ans << "\n";
}