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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll X;
    ll Q;
    cin >> X >> Q;
    vpll AB(Q);
    cin >> AB;
    vll tmp;
    tmp.emplace_back(X);
    priority_queue<ll> lpq;
    priority_queue<ll, vll, greater<ll>> rpq;
    tmp.emplace_back(AB[0].first);
    tmp.emplace_back(AB[0].second);
    sort(all(tmp));
    ll ans = tmp[1];
    cout << ans << "\n";
    lpq.emplace(tmp[0]);
    rpq.emplace(tmp[2]);
    for(ll i=1; i<Q; i++){
        if(AB[i].first <= ans && AB[i].second <= ans){
            rpq.emplace(ans);
            lpq.emplace(AB[i].first);
            lpq.emplace(AB[i].second);
            ans = lpq.top();
            lpq.pop();
        }else if(ans <= AB[i].first && ans <= AB[i].second){
            lpq.emplace(ans);
            rpq.emplace(AB[i].first);
            rpq.emplace(AB[i].second);
            ans = rpq.top();
            rpq.pop();
        }else{
            rpq.emplace(max(AB[i].first, AB[i].second));
            lpq.emplace(min(AB[i].first, AB[i].second));
        }
        cout << ans << "\n";
    }
}