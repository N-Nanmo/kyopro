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
    int N, Q;
    cin >> N >> Q;
    vll A;
    int afirst, bfirst;
    cin >> afirst >> bfirst;
    A.push_back(afirst);
    A.push_back(bfirst);
    sort(A.begin(), A.end());
    cyes;
    for(int i=1; i<Q; i++){
        int a, b;
        cin >> a >> b;
        int left=0, right=A.size()-1;
        while(left < right){
            int mid = (left + right) / 2;
            if(A[mid] < b) left = mid + 1;
            else right = mid;
        }
        if(A[left-1] <= a && A[right] >= a && A[left-1] <= b && A[right] >= b || (left == 0 || right == A.size()-1) && (A[0] >= a && A[0] >= b) || (A[A.size()-1] <= a && A[A.size()-1] <= b) || (A[0] >= a && A[A.size()-1] <= b) || (A[0] >= b && A[A.size()-1] <= a)){
            cyes;
            A.push_back(a);
            A.push_back(b);
            sort(A.begin(), A.end());
        }else{
            cno;
        }
        sort(A.begin(), A.end());
    }
}