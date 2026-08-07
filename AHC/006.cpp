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
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<pair<pair<int, int>, pair<int, int>>,int>> A(1000);
    for(int i=0; i<1000; i++){
        cin >> A[i].first.first.first >> A[i].first.first.second >> A[i].first.second.first >> A[i].first.second.second;
        A[i].second = i + 1;
    }
    sort(A.begin(), A.end(), [&](pair<pair<pair<int, int>, pair<int, int>>,int> a, pair<pair<pair<int, int>, pair<int, int>>,int> b){
        int a_point = 0;
        if(abs(a.first.first.first - a.first.second.first) + abs(a.first.first.second - a.first.second.second) <= abs(b.first.first.first - b.first.second.first) + abs(b.first.first.second - b.first.second.second)){
            a_point++;
        }else{
            a_point--;
        }
        if(abs(a.first.first.first - 400) + abs(a.first.first.second - 400) <= abs(b.first.first.first - 400) + abs(b.first.first.second - 400)){
            a_point++;
        }else{
            a_point--;
        }
        if(abs(a.first.second.first - 400) + abs(a.first.second.second - 400) <= abs(b.first.second.first - 400) + abs(b.first.second.second - 400)){
            a_point++;
        }else{
            a_point--;
        }
        if(a_point >= 0) return true;
        return false;
    });
    vector<pair<int, int>> deliver_a(50);
    vector<pair<int, int>> deliver_b(50);
    vector<int> choiced(50);
    for(int i=0; i<50; i++){
        deliver_a[i] = A[i].first.first;
        deliver_b[i] = A[i].first.second;
        choiced[i] = A[i].second;
    }
    cout << "50 ";
    for(int i=0; i<50; i++){
        cout << choiced[i] << " ";
    }
    cout << "\n";
    
    // 配達状態管理: 0=未集荷, 1=集荷済み未配達, 2=配達済み
    vector<int> status(50, 0);
    vector<bool> visited_pickup(50, false);
    vector<bool> visited_delivery(50, false);
    
    cout << "102 ";
    cout << "400 400 ";
    int crr_x = 400;
    int crr_y = 400;
    
    for(int step = 0; step < 100; step++){
        int best_idx = -1;
        int best_dist = INT_MAX;
        bool is_pickup = false;
        
        for(int i = 0; i < 50; i++){
            if(status[i] == 0 && !visited_pickup[i]){
                int dist = abs(crr_x - deliver_a[i].first) + abs(crr_y - deliver_a[i].second);
                if(dist < best_dist){
                    best_dist = dist;
                    best_idx = i;
                    is_pickup = true;
                }
            }
            if(status[i] == 1 && !visited_delivery[i]){
                int dist = abs(crr_x - deliver_b[i].first) + abs(crr_y - deliver_b[i].second);
                if(dist < best_dist){
                    best_dist = dist;
                    best_idx = i;
                    is_pickup = false;
                }
            }
        }
        
        if(is_pickup){
            cout << deliver_a[best_idx].first << " " << deliver_a[best_idx].second << " ";
            crr_x = deliver_a[best_idx].first;
            crr_y = deliver_a[best_idx].second;
            status[best_idx] = 1; // 集荷済み
            visited_pickup[best_idx] = true;
        } else {
            cout << deliver_b[best_idx].first << " " << deliver_b[best_idx].second << " ";
            crr_x = deliver_b[best_idx].first;
            crr_y = deliver_b[best_idx].second;
            status[best_idx] = 2; // 配達済み
            visited_delivery[best_idx] = true;
        }
    }
    cout << "400 400\n";
}