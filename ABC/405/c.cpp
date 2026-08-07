#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N,M,sum=0,C=1,k=1,Z=0;
    cin >> N;
    M=N;
    vector<int> A(N);
    cin >> A.at(0);
    for(int i=1;i<N;i++){
        cin >> A.at(i);
        Z += A.at(i);
    }
    for(int i=0;i<N-1;i++){
        sum += A.at(i)*Z;
        Z -= A.at(i+1);
    }
    cout << sum << endl;
}