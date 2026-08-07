#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N,H;
    cin >> N >> H;
    if(H==1){
        if(N>=1600&&N<=2999){
            cout << "Yes" << endl;
            return 0;
        }
    }else{
        if(N>=1200&&N<=2399){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}