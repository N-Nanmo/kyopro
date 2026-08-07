#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N,ans=0;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N, 0);
    vector<int> C(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i < N-1; i++) {
        if(A.at(i-1) < A.at(i)&& A.at(i) > A.at(i+1)) {
            B.at(i) = 1;
        }
        if(A.at(i-1) > A.at(i)&& A.at(i) < A.at(i+1)) {
            C.at(i) = 1;
        }
    }
    for(int i=0; i<N; i++){
        if(A.size() <= 4){
            break;
        }
        for(int j=0; j<A.size(); j++){
            bool a=false;
            bool b=false;
            bool c=false;
            vector<int> D(N);
            D = A;
            if(D.size() <= 4){
                break;
            }
            if(j != A.size()-1){
                if(D.at(j) < D.at(j+1)) {
                    c = true;
                }
            }
            if(c){
                for(int k=j; k<N; k++){
                    if(B.at(k) == 1){
                        a = true;
                    }
                    if(C.at(k) == 1){
                        b = true;
                    }
                }
            }
            if(a&&b){
                ans++;
            }
            D.erase(D.begin());
        }
        A.erase(A.begin());
    }
    cout << ans << endl;
}