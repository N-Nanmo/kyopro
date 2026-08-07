#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ull Q;
    cin >> Q;
    queue<ull> A;
    queue<ull> B;
    for(ull i=0; i<Q; i++){
        ull a,c;
        cin >> a >> c;
        if(a == 1){
            ull x;
            cin >> x;
            A.push(x);
            B.push(c);
        }else{
            ull b = B.front();
            ull f = A.front();
            if(c <= b){
                cout << f*c << endl;
                B.front() -= c;
                if(B.front() == 0){
                    B.pop();
                    A.pop();
                }
            }else{
                ull sum = 0;
                while(c > 0){
                    if(c >= B.front()){
                        sum += A.front() * B.front();
                        c -= B.front();
                        B.pop();
                        A.pop();
                    }else{
                        sum += A.front() * c;
                        B.front() -= c;
                        c = 0;
                    }
                }
                cout << sum << endl;
            }
        }
    }
}