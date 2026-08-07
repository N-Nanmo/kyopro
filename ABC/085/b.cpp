#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    set<int> S;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    cout << S.size() << endl;
}