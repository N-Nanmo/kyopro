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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, K;
    cin >> N >> K;
    vpll AB(N);
    cin >> AB;
    vll U;
    bool flag = false;
    ll crr = AB[0].second - AB[0].first;
    if(crr < 0) flag = false;
    if(crr >= 0) flag = true;
    ll sm = AB[0].first;
    for(ll i=1; i<N; i++){
        sm += AB[i].first;
        if(flag){
            if(AB[i].second >= AB[i].first){
                crr += AB[i].second - AB[i].first;
            }else{
                U.emplace_back(crr);
                crr = AB[i].second - AB[i].first;
                flag = false;
            }
        }else{
            if(AB[i].second <= AB[i].first){
                crr += AB[i].second - AB[i].first;
            }else{
                U.emplace_back(crr);
                crr = AB[i].second - AB[i].first;
                flag = true;
            }
        }
    }
    U.emplace_back(crr);
    ll l = 0;
    crr = 0;
    vll ans;
    for(ll r=0; r<U.size(); r++){
        crr += U[r];
        while(crr < 0 && l <= r){
            crr -= U[l];
            l++;
        }
        if(crr != 0) ans.emplace_back(crr);
    }
    sort(rall(ans));
    for(ll i=0; i<min((ll)ans.size(), K); i++){
        sm += ans[i];
    }
    cout << sm << "\n";
}