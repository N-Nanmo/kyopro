#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B, C,X,sum=0;
    cin >> A >> B >> C >> X;
    for(int i=0;i<A+1;i++){
        for(int j=0;j<B+1;j++){
            for(int k=0;k<C+1;k++){
                if(i*500+j*100+k*50==X){
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
}