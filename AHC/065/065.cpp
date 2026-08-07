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
inline istream& operator>>(istream& is, vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i];
    }
    return is;
}
template <typename T, typename U>
inline istream& operator>>(istream& is, vector<pair<T, U>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i].first >> v[i].second;
    }
    return is;
}
template <typename T>
inline istream& operator>>(istream& is, vector<vector<T>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            is >> v[i][j];
        }
    }
    return is;
}
template <typename T, typename U, typename S, typename V>
inline istream& operator>>(istream& is,
                           vector<pair<pair<T, U>, pair<S, V>>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i].first.first >> v[i].first.second >> v[i].second.first >>
            v[i].second.second;
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R;
    cin >> R;
    vvi Y(R, vi(R));
    cin >> Y;
    vector<stack<int>> T(R);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            T[j].push(Y[i][j]);
        }
    }
    vector<stack<int>> S(R);
    vector<pair<pi, int>> sch;
    int crrcnt = 0;
    vb gone(R, true);
    vi K;
    vector<pair<pi, pi>> ans;
    auto appendGroups = [&](vector<pi> pairs) {
        while (!pairs.empty()) {
            vector<tuple<int, int, int>> ord;
            ord.reserve((int)pairs.size());
            for (int i = 0; i < (int)pairs.size(); i++) {
                ord.emplace_back(pairs[i].first, pairs[i].second, i);
            }

            sort(all(ord), [](const auto& x, const auto& y) {
                if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
                return get<1>(x) > get<1>(y);
            });

            vector<int> tails;
            vector<int> tailsIdx;
            vector<int> prv((int)ord.size(), -1);
            tails.reserve((int)ord.size());
            tailsIdx.reserve((int)ord.size());

            for (int i = 0; i < (int)ord.size(); i++) {
                int b = get<1>(ord[i]);
                int pos = (int)(lower_bound(all(tails), b) - tails.begin());
                if (pos == (int)tails.size()) {
                    tails.push_back(b);
                    tailsIdx.push_back(i);
                } else {
                    tails[pos] = b;
                    tailsIdx[pos] = i;
                }
                if (pos > 0) prv[i] = tailsIdx[pos - 1];
            }

            vector<char> used((int)pairs.size(), false);
            int cur = tailsIdx.back();
            int grpSize = 0;
            while (cur != -1) {
                used[get<2>(ord[cur])] = true;
                grpSize++;
                cur = prv[cur];
            }
            K.emplace_back(grpSize);

            vector<pi> nxt;
            nxt.reserve((int)pairs.size() - grpSize);
            for (int i = 0; i < (int)pairs.size(); i++) {
                if (!used[i]) nxt.emplace_back(pairs[i]);
            }
            pairs.swap(nxt);
        }
    };
    // 各待避線にふりわけ
    while (ans.size() < R*R) {
        for (int i = 0; i < R; i++) {
            if(T[i].size() == 0) continue;
            int a = T[i].top();
            T[i].pop();
            if (gone[i]) {
                sch.emplace_back(pi{i, a}, 1);
            }
            while (T[i].size() > 0 && T[i].top() / 10 == a / 10) {
                sch.back().second++;
                T[i].pop();
            }
            gone[i] = false;
        }
        vector<pair<pi, int>> outPair;
        if (!sch.empty()) {
            vector<tuple<int, int, int>> ord;
            ord.reserve((int)sch.size());
            for (int i = 0; i < (int)sch.size(); i++) {
                ord.emplace_back(sch[i].first.first, sch[i].first.second / 10,
                                 i);
            }

            sort(all(ord), [](const auto& x, const auto& y) {
                if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
                return get<1>(x) > get<1>(y);
            });

            vector<int> tails;
            vector<int> tailsIdx;
            vector<int> prv((int)ord.size(), -1);
            tails.reserve((int)ord.size());
            tailsIdx.reserve((int)ord.size());

            for (int i = 0; i < (int)ord.size(); i++) {
                int b = get<1>(ord[i]);
                int pos =
                    (int)(lower_bound(all(tails), b) - tails.begin());
                if (pos == (int)tails.size()) {
                    tails.push_back(b);
                    tailsIdx.push_back(i);
                } else {
                    tails[pos] = b;
                    tailsIdx[pos] = i;
                }
                if (pos > 0) prv[i] = tailsIdx[pos - 1];
            }

            int cur = tailsIdx.back();
            while (cur != -1) {
                outPair.emplace_back(sch[get<2>(ord[cur])]);
                cur = prv[cur];
            }
            reverse(all(outPair));
        }
        K.emplace_back(outPair.size());
        for (auto op : outPair) {
            S[op.first.second/10].emplace(op.first.second);
            gone[op.first.first] = true;
            ans.emplace_back(pair(pi(0, op.first.first), pi(op.first.second, op.second)));
        }
    }

    // 待避線1~Rまで順に並べかえ
    for(int i=0; i<R; i++){
        int phase1Begin = (int)ans.size();
        int crr = -1;
        int tmp = S[i].size();
        for(int j=0; j<tmp; j++){
            if(S[i].size() == 0) break;
            crr = S[i].top();
            S[i].pop();
            int goT = crr%10;
            T[goT].emplace(crr);
            int cnt = 1;
            if(S[i].size() != 0 && crr < S[i].top()){
                T[goT].emplace(S[i].top());
                S[i].pop();
                j++;
                cnt++;
            }
            ans.emplace_back(pair(pi(1, i), pi(goT, cnt)));
        }
        {
            vector<pi> pairs;
            pairs.reserve((int)ans.size() - phase1Begin);
            for (int idx = phase1Begin; idx < (int)ans.size(); idx++) {
                int a = ans[idx].first.second;
                int b = ans[idx].second.first;
                pairs.emplace_back(a, b);
            }
            appendGroups(pairs);
        }
        
        int phase2Begin = (int)ans.size();
        for (int d = 9; d >= 0; d--) {
            int cnt = 0;
            while (!T[d].empty() && T[d].top() / 10 == i) {
                int v = T[d].top();
                T[d].pop();
                S[i].emplace(v);
                cnt++;
            }
            if (cnt > 0) {
                ans.emplace_back(pair(pi(0, d), pi(i * 10 + d, cnt)));
            }
        }
        {
            vector<pi> pairs;
            pairs.reserve((int)ans.size() - phase2Begin);
            for (int idx = phase2Begin; idx < (int)ans.size(); idx++) {
                int a = ans[idx].first.second;
                int b = ans[idx].second.first / 10;
                pairs.emplace_back(a, b);
            }
            appendGroups(pairs);
        }
    }
    cout << reduce(all(K), 0) << "\n";
    for(auto k : K){
        cout << k << "\n";
        for(int i=0; i<k; i++){
            cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first/10 << " " << ans[i].second.second << "\n";
        }
    }
}