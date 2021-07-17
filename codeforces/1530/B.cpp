#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int h, w;
    cin>>h>>w;
    vector<vector<int>> a(h, vector<int> (w));
    for(int i=0; i<h; i+=2) {
        a[i][0]=1;
    }
    for(int j=0; j<w; j+=2) {
        a[0][j]=1;
    }
    for(int i=h-1; i>1; i-=2) {
        a[i][w-1]=1;
    }
    for(int j=w-1; j>1; j-=2) {
        a[h-1][j]=1;
    }
    for(auto i : a) {
        for(auto j : i) {
            cout<<j;
        }
        cout<<endl;
    }
    cout<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

