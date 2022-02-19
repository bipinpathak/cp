#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    vector<vector<int>> options={{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    int a, b, p, q;
    for(int i=0; i<4; i++) {
        a=x1+options[i][0], b=y1+options[i][1]; 
        p=abs(x2-a), q=abs(y2-b);
        if(min(p, q)==1 && max(p, q)==2) {
            cout<<"Yes"<<endl;
            return;
        }
        a=x1+options[i][1], b=y1+options[i][0]; 
        p=abs(x2-a), q=abs(y2-b);
        if(min(p, q)==1 && max(p, q)==2) {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

