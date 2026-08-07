#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    set<string> st;
    vector<string> S(N);
    for(int i=0; i<N; i++) cin >> S[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j)continue;
            st.insert(S[i] + S[j]);
        }
    }
    cout << st.size() << "\n";
}