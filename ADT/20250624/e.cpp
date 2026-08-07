#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    cout << "Yes" << endl;
    int a=1,b=1;
    while(a < N - 1 && b < M - 1){
        if(A[a] == B[b]){
            cout << "Yes" << endl;
            a++;
            b++;
        }else{
            cout << "No" << endl;
            a++;
        }
    }
    for(int i=a; i<N-1; i++){
        cout << "No" << endl;
    }
    cout << "Yes" << endl;
}