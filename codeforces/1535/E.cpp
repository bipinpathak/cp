#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll a, c;
};

void solve() {
    int q;
    cin>>q;
    vector<node> a(q+1);
    vector<vector<int>> p(q+1, vector<int> (20, -1));
    cin>>a[0].a>>a[0].c;
    for(int i=1; i<=q; i++) {
        int type;
        cin>>type;
        if(type==1) {
            int u;
            cin>>u;
            cin>>a[i].a>>a[i].c;
            p[i][0]=u;
            for(int j=1; j<20 && p[i][j-1]>=0; j++) {
                p[i][j]=p[p[i][j-1]][j-1];
            }
        } else {
            ll v, w;
            cin>>v>>w;
            ll money=0, weight=0;
            while(w) {
                int u=v;
                for(int j=19; j>=0; j--) {
                    if(p[u][j]>=0 && a[p[u][j]].a) {
                        u=p[u][j];
                    }
                }
                ll take=min(a[u].a, w);
                a[u].a-=take;
                w-=take;
                money+=take*a[u].c;
                weight+=take;
                if(u==v) {
                    break;
                }
            }
            cout<<weight<<" "<<money<<endl;
        }
    }
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

