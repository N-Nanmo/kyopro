#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int X, A, B;
    cin >> X >> A >> B;
    cout << max((X-A)%B, 0);
}