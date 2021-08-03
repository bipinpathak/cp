#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool inside(vector<int> p, int n, int d) {
    if(p[1]<p[0]-d) {
        return false;
    }
    if(p[1]>p[0]+d) {
        return false;
    }
    if(p[1]<d-p[0]) {
        return false;
    }
    if(p[1]>2*n-d-p[0]) {
        return false;
    }
    return true;
}

void solve() {
    int n, d, m;
    cin>>n>>d>>m;
    vector<vector<int>> a(m, vector<int> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }       
        string ans="NO";
        if(inside(i, n, d)) {
            ans="YES";
        }   
        cout<<ans<<endl;
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

