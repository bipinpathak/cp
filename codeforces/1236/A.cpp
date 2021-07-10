#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin>>a>>b>>c;
    int x=min(a,b/2), y=min(b, c/2);
    if(2*x+y>b) {
        x=(b-y)/2;
    }
    cout<<3*(x+y)<<endl;
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
