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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvf = vector<vector<float>>;
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
inline istream& operator>>(istream& is, vector<T>& v) {
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i];
    }
    return is;
}
template <typename T>
inline istream& operator>>(istream& is, vector<pair<T, T>>& v) {
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i].first >> v[i].second;
    }
    return is;
}
template <typename T>
inline istream& operator>>(istream& is, vector<vector<T>>& v) {
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            is >> v[i][j];
        }
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll H, W, N;
    cin >> H >> W >> N;
    vector<pair<pll, ll>> HW(N);
    vector<pair<pll, ll>> Hs(N);
    vector<pair<pll, ll>> Ws(N);
    for (int i = 0; i < N; i++) {
        cin >> HW[i].first.first >> HW[i].first.second;
        HW[i].second = i;
    }
    Hs = HW;
    Ws = HW;
    vb B(N);
    sort(rall(Hs));
    sort(all(Ws), [](auto const& l, auto const& r) {
        return l.first.second > r.first.second;
    });
    bool wasH = true;
    if (Ws[0].first.second == W) wasH = false;
    ll h = 0, w = 0;
    ll crrh = H, crrw = W;
    vector<pair<pll, ll>> ans;
    while (h < N || w < N) {
        while ((h < N && w < N) &&
               !(Hs[h].first.first == crrh && B[Hs[h].second] == false ||
                 Ws[w].first.second == crrw && B[Ws[w].second] == false)) {
            if(!wasH)h++;
            else w++;
        }
        if (Hs[h].first.first == crrh && B[Hs[h].second] == false) {
            ans.emplace_back(make_pair(
                make_pair(crrh - Hs[h].first.first+1, crrw - Hs[h].first.second+1),
                Hs[h].second));
            crrw -= Hs[h].first.second;
            B[Hs[h].second] = true;
            h++;
            wasH = true;
        } else if(Ws[w].first.second == crrw && B[Ws[w].second] == false){
            ans.emplace_back(make_pair(crrh - Ws[w].first.first+1, crrw - Ws[w].first.second+1), Ws[w].second);
            crrh -= Ws[w].first.first;
            B[Ws[w].second] = true;
            w++;
            wasH = false;
        }else{
            break;
        }
    }
    sort(all(ans), [](auto const& l, auto const&r){
        return l.second < r.second;
    });
    for(int i=0; i<ans.size(); i++){
        cout << ans[i].first.first << " " << ans[i].first.second << "\n";
    }
}