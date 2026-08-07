#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N,Q,cnt=0;
    cin >> N >> Q;
    vector<bool> M(N, false);
    if(Q == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i=0; i<Q; i++){
        int a;
        cin >> a;
        if(M[a-1]){
            M[a-1] = false;
            if(a != 1 && a != N){
                if(!M[a-2] && !M[a]){
                    cnt--;
                }else if(M[a-2] && M[a]){
                    cnt++;
                }
            }else if(a==1){
                if(!M[a]){
                    cnt--;
                }
            }else if(a == N){
                if(!M[a-2]){
                    cnt--;
                }
            }
        }else if(!M[a-1]){
            M[a-1] = true;
            if(a != 1 && a != N){
                if(!M[a-2] && !M[a]){
                    cnt++;
                }else if(M[a-2] && M[a]){
                    cnt--;
                }
            }else if(a==1){
                if(!M[a]){
                    cnt++;
                }
            }else if(a==N){
                if(!M[a-2]){
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}