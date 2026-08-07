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
    ll T;
    cin >> T;
    while(T--){
        vpll spell;
        for(int i=0; i<26; i++){
            spell.emplace_back(make_pair(0, 'a'+i));
        }
        string S;
        cin >> S;
        for(ll i=0; i<S.size(); i++){
            spell[S[i]-'a'].first++;
        }
        bool muri = false;
        for(int i=0; i<26; i++){
            if(spell[i].first >= (S.size()+1)/2+1){
                cno;
                muri = true;
                break;
            }
        }
        if(muri){
            continue;
        }
        cyes;
        sort(rall(spell));
        ll l=0, r=spell.size();
        for(int i=spell.size(); i>=0; i--){
            if(spell[i].first >= 1){
                break;
            }
            r--;
        }
        cout << (char)(spell[1].second);
        spell[1].first--;
        for(ll i=0;;){
            while(spell[l].first <= 0){
                l++;
            }
            cout << (char)(spell[l].second);
            spell[l].first--;
            i++;
            if(i>=S.size()){
                break;
            }
            while(spell[r].first <= 0){
                r--;
            }
            cout << (char)(spell[r].second);
            spell[r].first--;
            i++;
            if(i>=S.size()){
                break;
            }
        }
        cout << "\n";
    }
}