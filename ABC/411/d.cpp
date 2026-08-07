#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<tuple<int,int,string>> Que(Q);
    bool server = true;
    int pc = 0;
    string ans = "";
    for(int i=0; i<Q; i++){
        int q,r;
        cin >> q >> r;
        if(q == 2){
            string s;
            cin >> s;
            Que[i] = make_tuple(q,r,s);
        }else{
            Que[i] = make_tuple(q,r,"");
        }
    }
    for(int i=Q-1; i>=0; i--){
        int q = get<0>(Que[i]);
        if(q == 1 && !server){
            int r = get<1>(Que[i]);
            if(r == pc){
                server = true;
            }

        }else if(q == 2 && !server){
            int r = get<1>(Que[i]);
            if(r == pc){
                string s = get<2>(Que[i]);
                reverse(s.begin(),s.end());
                ans += s;
            }
        }else if(q == 3 && server){
            int p = get<1>(Que[i]);
            pc = p;
            server = false;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}